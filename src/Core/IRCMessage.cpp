#include "IRCMessage.h"

#include <QRegularExpression>
#include <QStringBuilder>

namespace Ostrich {

const QString JOIN_MESSAGE = "Welcome to #CHANNEL_NAME's chat room!";
const QString PART_MESSAGE = "You have left #CHANNEL_NAME's chat room.";

// This ugly regex will help us parse any received IRC message
const QRegularExpression IRC_PROTOCOL_REGEX("^(?:[:](\\S+)!)(?:\\S+) (\\S+)(?: #(?!:)(.+?))?(?: [:](.+))?$");

// This regex extracts a message from the /me specification if it exists
const QRegularExpression IRC_ME_MESSAGE_PROTOCOL("(?:\1ACTION\\s)(.*)\1");
// Parses IRCMessage from QString
IRCMessage::IRCMessage(const QString& string) : messageFlags(0) {
	rawString = string;

	parseVariablesFromRaw();

	update();
}

// Parses IRCMessage from byteArray
// Simply transform the byteArray into a QString
IRCMessage::IRCMessage(const QByteArray& raw) : messageFlags(0) {
	rawString = QString(raw);

	parseVariablesFromRaw();

	update();
}


IRCMessage::IRCMessage(const QString& type, const QString& text) : messageFlags(0) {
	messageType = IRCMessageType(type);
	message = text.simplified();

	timestamp = timestamp.currentDateTime();

	update();
}

void IRCMessage::parseVariablesFromRaw() {
	QRegularExpressionMatch details = IRC_PROTOCOL_REGEX.match(rawString);

	if (details.hasMatch()) {
		sentBy = details.captured(1);
		messageType = IRCMessageType(details.captured(2));
		channelName = details.captured(3).toLower();
		message = details.captured(4);

		// Clean message of return carriages and excess whitespace
		message = message.simplified();

		assignMessageFlags();
	}

	timestamp = timestamp.currentDateTime();
}

// Assign the bit flags (ACTION, COMMAND, etc) to this IRCMessage
void IRCMessage::assignMessageFlags() {
	QRegularExpressionMatch meProtocol = IRC_ME_MESSAGE_PROTOCOL.match(message);

	// Test if string starts with /me identifier
	if (meProtocol.hasMatch()) {
		messageFlags = messageFlags | ActionMessage;

		message = meProtocol.captured(1);
	}
}

// Called every time a member variable is changed
void IRCMessage::update() {
	buildCommandString();
	buildDisplayString();
}

void IRCMessage::buildCommandString() {
	commandString = "";

	if (messageType.is("JOIN") || messageType.is("PART")) {
		commandString = messageType.get() % " #" % message;
	} else if (messageType.is("PRIVMSG")) {
		commandString = "PRIVMSG #" % channelName % " :" % message;
	} else {
		commandString = messageType.get() % " " % message;
	}
}

// TODO: Append time
void IRCMessage::buildDisplayString() {
	displayString = "";

	if (messageType.is("JOIN")) {
		displayString = JOIN_MESSAGE;
		displayString = displayString.replace("#CHANNEL_NAME", message);
	} else if (messageType.is("PART")) {
		displayString = PART_MESSAGE;
		displayString = displayString.replace("#CHANNEL_NAME", message);
	} else if (messageType.is("PRIVMSG")) {
		displayString = sentBy % ": " % message;
	}
}

// Setters/Getters. Setters always call update() after changing variables to update strings
void IRCMessage::setChannel(const QString& channel) {
	channelName = channel;

	update();
}
void IRCMessage::setMessage(const QString& newMessage) {
	message = newMessage;

	update();
}

void IRCMessage::setSentBy(const QString& who) {
	sentBy = who;

	update();
}

QString IRCMessage::getMessageType() const {
	return messageType.get();
}

QDateTime IRCMessage::getTimeStamp() const {
	return timestamp;
}

QString IRCMessage::getMessage() const {
	return message;
}

QString IRCMessage::getSentBy() const {
	return sentBy;
}

QString IRCMessage::getChannel() const {
	return channelName;
}

QString IRCMessage::getCommandString() const {
	return commandString;
}

QString IRCMessage::getDisplayString() const {
	return displayString;
}

//namespace Ostrich
}