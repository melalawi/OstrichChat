#include "ChannelConnection.h"

#include "ServerConnection.h"
#include "IRCMessage.h"

namespace Ostrich {

ChannelConnection::ChannelConnection(const QString& channel, ServerConnection *parent) : QObject(parent) {
	parentSocket = parent;
	channelName = channel.toLower();

	assignSlots();
}

ChannelConnection::~ChannelConnection() {}

void ChannelConnection::assignSlots() {}

void ChannelConnection::channelJoin() {
	if (parentSocket) {
		IRCMessage join = generateIRCMessage("JOIN");

		join.assignVariable("channel", channelName);

		// TODO: REMOVE, BAD
		join.updateInternalVariables();

		// TODO: Only if connection established
		IRCSendSilent(join);
	}
}

void ChannelConnection::channelLeave() {
	if (parentSocket) {
		IRCMessage part = generateIRCMessage("PART");

		part.assignVariable("channel", channelName);

		// TODO: REMOVE, BAD
		part.updateInternalVariables();

		IRCSendSilent(part);

		// TODO: Only when PART succeeds
		parentSocket->removeChannelConnection(this);
	}
}

void ChannelConnection::sendPRIVMSG(const QString& string) {
	if (parentSocket) {
		QString user = parentSocket->getUser();
		IRCMessage message = generateIRCMessage("PRIVMSG", string, user, channelName);

		// TODO: Change, as having to call this with every message is bad and contrived
		message.updateInternalVariables();

		IRCSendMessage(message);
	}
}

// Emit appropriate receive signal (UI updating)
void ChannelConnection::IRCReceiveMessage(const IRCMessage& message) {
	emit messageReceivedSignal(message);
	emit lineReceivedSignal(message.displayString());
}

// Emit appropriate send signal (ServerConnection updating)
void ChannelConnection::IRCSendMessage(IRCMessage message) {
	emit messageSentSignal(message);
	emit lineSentSignal(message.displayString());
}

// Silent sending, without calling lineSentSignal
void ChannelConnection::IRCSendSilent(IRCMessage message) {
	emit messageSentSignal(message);
}

QString ChannelConnection::getChannelName() const {
	return channelName;
}

//namespace Ostrich
}