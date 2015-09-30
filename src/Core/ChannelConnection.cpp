#include "ChannelConnection.h"

#include "ServerConnection.h"

ChannelConnection::ChannelConnection(const QString& channel, ServerConnection *parent) : QObject(parent) {
	parentSocket = parent;
	channelName = channel.toLower();

	assignSlots();
}

ChannelConnection::~ChannelConnection() {}

void ChannelConnection::assignSlots() {}

void ChannelConnection::channelJoin() {
	if (parentSocket) {
		// TODO: Only if connection established
		IRCSendMessage(IRCMessage("JOIN", channelName));
	}
}

void ChannelConnection::channelLeave() {
	if (parentSocket) {
		IRCSendMessage(IRCMessage("PART", channelName));

		parentSocket->removeChannel(this);
	}
}

void ChannelConnection::IRCSendMessage(const IRCMessage& message) {
	parentSocket->outputString(message.getCommandString());

	emit onMessageSent(message);
}

// Emit appropriate receive signal (UI updating)
void ChannelConnection::IRCReceiveString(const QString& string) {
	emit onMessageReceived(IRCMessage(string));
}

// Emit appropriate send signal (ServerConnection updating)
void ChannelConnection::IRCSendString(const QString& string) {
	if (parentSocket) {
		QString user = parentSocket->getUser();

		IRCMessage message("PRIVMSG", string);
		message.setChannel(channelName);
		message.setSentBy(user);

		IRCSendMessage(message);
	}
}

QString ChannelConnection::getChannelName() const {
	return channelName;
}