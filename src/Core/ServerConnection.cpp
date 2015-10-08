#include "ServerConnection.h"

#include <iostream>

#include "ChannelConnection.h"

namespace Ostrich {

const QString TWITCH_HOST = "irc.twitch.tv";
const int TWITCH_PORT = 6667;

ServerConnection::ServerConnection(QObject *parent) : QTcpSocket(parent) {
	// Not currently connected to the server
	isConnected = false;
	isLoggedIn = false;

	assignSlots();
}

ServerConnection::~ServerConnection() {}

void ServerConnection::assignSlots() {
	// Processes any IRC input
	connect(this, SIGNAL(readyRead()), this, SLOT(processReadyRead()));

	// Fired when a successful connection to the server has been made
	connect(this, SIGNAL(connected()), this, SLOT(onServerConnection()));
}

void ServerConnection::twitchConnect(const QString& user, const QString& oauth) {
	username = user;
	oAuthToken = oauth;

	// onServerConnection should be fired on successful connection, login happens there
	connectToHost(TWITCH_HOST, TWITCH_PORT);
}

void ServerConnection::onServerConnection() {
	IRCMessage oAuthInput = generateIRCMessage("PASS", oAuthToken);
	IRCMessage userInput = generateIRCMessage("NICK");

	userInput.assignVariable("user", username);

	// We have connected to the server, wait for login
	isConnected = true;

	// TODO: REMOVE, BAD, CONTRIVED
	oAuthInput.updateInternalVariables();
	userInput.updateInternalVariables();

	// Send login information through IRC
	outputString(oAuthInput.commandString());
	outputString(userInput.commandString());

	// TODO: Wait for response before setting bool
	isLoggedIn = true;
}

void ServerConnection::twitchDisconnect() {
	disconnectFromHost();

	isConnected = false;
	isLoggedIn = false;
}

ChannelConnection *ServerConnection::addChannelConnection(const QString& channelName) {
	ChannelConnection *newChannel = nullptr;

	// Only attempt this if we're connected and stuff
	if (!isConnected) {
		std::cout << "Error: Not connected to server." << std::endl;
	} else if (!isLoggedIn) {
		std::cout << "Error: Not logged in. Please log in. Thanks." << std::endl;
	} else {
		newChannel = new ChannelConnection(channelName, this);

		// Connect to its send signal
		connect(newChannel, SIGNAL(messageSentSignal(const IRCMessage&)), this, SLOT(sendMessageSlot(const IRCMessage&)));

		// TODO: Channel validity check
		channels.push_back(newChannel);
	}

	return newChannel;
}

// Loop through all channels, find matching channel name, remove it from the vector
void ServerConnection::removeChannelConnection(const QString& channelName) {
	int channelIndex = getChannelIndex(channelName);

	if (channelIndex != -1) {
		channels.erase(channels.begin() + channelIndex);
	}
}

void ServerConnection::removeChannelConnection(ChannelConnection *purge) {
	if (purge) {
		int channelIndex = getChannelIndex(purge->getChannelName());

		if (channelIndex != -1) {
			channels.erase(channels.begin() + channelIndex);
		}
	}
}

// Retrieve the channel with the specified name (if it exists, otherwise returns nullptr)
ChannelConnection *ServerConnection::getChannelConnection(const QString& channelName) {
	ChannelConnection *result = nullptr;
	int channelIndex = getChannelIndex(channelName);

	if (channelIndex != -1) {
		result = channels.at(channelIndex);
	}

	return result;
}

// Only vector iteration happens here, everything else that needs to search calls this function
int ServerConnection::getChannelIndex(const QString& channelName) {
	int result = -1;

	for (int index = 0; index < channels.size(); ++index) {
		ChannelConnection *currentChannel = channels.at(index);

		if (QString::compare(currentChannel->getChannelName(), channelName, Qt::CaseInsensitive) == 0) {
			result = index;
			break;
		}
	}

	return result;
}

QString ServerConnection::getUser() const {
	return username;
}

// Private Slots
void ServerConnection::sendMessageSlot(const IRCMessage& message) {
	outputString(message.commandString());
}

void ServerConnection::processReadyRead() {
	QByteArray next;

	do {
		next = readLine();

		processInput(QString(next));
	} while (next.length());
}

// Send a received IRC Message to the appropriate channel
void ServerConnection::processInput(const QString& input) {
	IRCMessage message = parseIncomingIRCMessage(input);
	QString channelName = message.getVariableValue("channel");
	ChannelConnection *channel = nullptr;

	if (channelName.length()) {
		channel = getChannelConnection(channelName);

		if (channel) {
			channel->IRCReceiveMessage(message);
		}
	}
}

void ServerConnection::outputString(const QString& text) {
	std::string stringified = text.toStdString() + "\r\n";

	write(stringified.c_str());
	flush();
}

//namespace Ostrich
}