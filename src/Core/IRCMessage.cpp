#include "IRCMessage.h"

#include <iostream>
#include <QRegularExpression>
#include <QStringBuilder>

namespace Ostrich {

// Each IRCMessage contains a QHash of the following defined variable names
const std::initializer_list<std::pair<QString, QString>> DEFAULT_MESSAGE_VARIABLES = {
	std::pair<QString, QString>("user", "undefined"),
	std::pair<QString, QString>("channel", "undefined"),
	std::pair<QString, QString>("message", "undefined"),
	std::pair<QString, QString>("time", "undefined")
};

const QHash<QString, QString> IRC_DISPLAY_LIST (std::initializer_list<std::pair<QString, QString>>{
	std::pair<QString, QString>("JOIN", "Welcome to $channel^'s chat room!"),
	std::pair<QString, QString>("PART", "You have left $channel^'s chat room."),
	std::pair<QString, QString>("NICK", "You are known as $user^."),
	std::pair<QString, QString>("PRIVMSG", "$time^ $user^: $message^"),
	std::pair<QString, QString>("QUIT", "undefined") // TODO: implement
});

const QHash<QString, QString> IRC_COMMAND_LIST(std::initializer_list<std::pair<QString, QString>>{
	std::pair<QString, QString>("JOIN", "JOIN #$channel^"),
	std::pair<QString, QString>("PART", "PART #$channel^"),
	std::pair<QString, QString>("NICK", "NICK $user^"),
	std::pair<QString, QString>("PASS", "PASS $message^"),
	std::pair<QString, QString>("PRIVMSG", "PRIVMSG #$channel^ :$message^"),
	std::pair<QString, QString>("QUIT", "undefined") // TODO: implement
});

// This ugly regex will help us parse any received IRC message
const QRegularExpression IRC_PROTOCOL_REGEX("^(?:[:](\\S+)!)(?:\\S+) (\\S+)(?: #(?!:)(.+?))?(?: [:](.+))?$");

// This regex extracts a message from the /me specification if it exists
const QRegularExpression IRC_ME_MESSAGE_PROTOCOL("(?:\1ACTION\\s)(.*)\1");

// Best way to create IRCMessage instances
IRCMessage generateIRCMessage(const QString& type, const QString& message, const QString& user, const QString& channel) {
	IRCMessageType messageType(type);
	IRCMessage result(messageType);

	result.assignVariable("message", message);
	result.assignVariable("user", user);
	result.assignVariable("channel", channel);

	return result;
}

// Parses IRCMessage from QString
IRCMessage parseIncomingIRCMessage(const QString& rawString) {
	IRCMessage result;
	QRegularExpressionMatch details;
	IRCMessageType messageType;

	details = IRC_PROTOCOL_REGEX.match(rawString);

	if (details.hasMatch()) {
		messageType = IRCMessageType(details.captured(2).simplified());
		result = IRCMessage(messageType);

		result.assignVariable("user", details.captured(1).simplified());
		result.assignVariable("channel", details.captured(3).simplified());
		result.assignVariable("message", details.captured(4).simplified());

		// Called once you're done with adding/changing variables
		result.updateInternalVariables();
	}

	return result;
}


IRCMessage::IRCMessage() : messageFlags(0) {
	cVariables = QHash<QString, QString>(DEFAULT_MESSAGE_VARIABLES);

	cVariables.insert("time", timestamp.currentDateTime().time().toString("hh:mm a"));
}

IRCMessage::IRCMessage(IRCMessageType type) : IRCMessage() {
	messageType = type;
}

// Clean up variables, assign various message flags (command, ACTION, etc)
void IRCMessage::updateInternalVariables() {
	QString message, channel;

	// Assign bit flags first (modifies the message)
	assignMessageFlags();

	// Clean message of return carriages and excess whitespace, lower channel casing
	message = cVariables.value("message").simplified();
	channel = cVariables.value("channel").toLower();

	cVariables.insert("message", message);
	cVariables.insert("channel", channel);

	commString = buildString(IRC_COMMAND_LIST);
	dispString = buildString(IRC_DISPLAY_LIST);
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

// Assign custom variable (only modifies already existing bucket, does not create new buckets)
void IRCMessage::assignVariable(const QString& varName, const QString& varValue) {
	if (!cVariables.contains(varName)) {
		std::cout << "Error: IRCMessage varName \"" + varName.toStdString() + "\" does not exist.";
	} else {
		// Does this replace or append the new varValue?
		cVariables.insert(varName, varValue);
	}
}

// Simple custom variable retrieval
QString IRCMessage::getVariableValue(const QString& varName) const {
	QString result = "";

	if (!cVariables.contains(varName)) {
		std::cout << "Error: IRCMessage varName \"" + varName.toStdString() + "\" does not exist.";
	} else {
		result = cVariables.value(varName);
	}

	return result;
}

// TODO: Append time
// Builds the requested string type out of the saved variables
QString IRCMessage::buildString(const QHash<QString, QString>& list) const {
	QString result = "";

	if (list.contains(messageType.get())) {
		result = list.value(messageType.get());

		QHashIterator<QString, QString> varIterator(cVariables);

		// Loops through all cVars and replaces them in the string
		while (varIterator.hasNext()) {
			varIterator.next();
			QString key = varIterator.key(), val = varIterator.value();

			result = result.replace("$" + varIterator.key() + "^", varIterator.value());
		}
	}

	return result;
}

// Simple getters
QString IRCMessage::displayString() const {
	return dispString;
}

QString IRCMessage::commandString() const {
	return commString;
}
//namespace Ostrich
}