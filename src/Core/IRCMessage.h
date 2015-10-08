#pragma once

#include <array>
#include <QByteArray>
#include <QFlags>
#include <QHash>
#include <QString>
#include <QDateTime>

namespace Ostrich {

const std::array<QString, 7> IRC_VALID_TYPES = {
	"NULLTYPE",
	"PRIVMSG",
	"JOIN",
	"PART",
	"NICK",
	"PASS",
	"QUIT"
};

class IRCMessageType {
private:
	QString val;

public:
	IRCMessageType() {
		set(IRC_VALID_TYPES.at(0));
	}

	IRCMessageType(const QString& input) {
		set(input);
	}

	void set(const QString& input) {
		val = IRC_VALID_TYPES.at(0);

		for (auto type : IRC_VALID_TYPES) {
			if (input == type) {
				val = type;
				break;
			}
		}
	}

	QString get() const {
		return val;
	}

	bool is(const QString& input) const {
		return val == input;
	}
};

class IRCMessage {
private:
	IRCMessageType messageType;
	QFlag messageFlags;

	QHash<QString, QString> cVariables;

	QString commString;
	QString dispString;

	QString sentBy;
	QString message;
	QString channelName;
	QDateTime timestamp;

	void assignMessageFlags();

	QString buildString(const QHash<QString, QString>& list) const;
public:
	IRCMessage();
	IRCMessage(IRCMessageType type);

	void assignVariable(const QString& varName, const QString& varValue);
	QString getVariableValue(const QString& varName) const;

	void updateInternalVariables();

	QString commandString() const;
	QString displayString() const;

	// Message Flag options
	enum MessageTypes {
		ActionMessage = 1,
		WhisperMessage = 2,
		CommandSlashMessage = 4,
		CommandExclamMessage = 8
	};
	Q_DECLARE_FLAGS(Options, MessageTypes)
};

Q_DECLARE_OPERATORS_FOR_FLAGS(IRCMessage::Options)

IRCMessage parseIncomingIRCMessage(const QString& text);
IRCMessage generateIRCMessage(const QString& type, const QString& message = "", const QString& user = "", const QString& channel = "");

//namespace Ostrich
}