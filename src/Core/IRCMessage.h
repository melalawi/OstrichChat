#pragma once

#include <array>
#include <QByteArray>
#include <QString>
#include <QDateTime>

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
	QDateTime timestamp;

	QString rawString;
	QString commandString;
	QString displayString;

	QString sentBy;
	QString message;
	QString channelName;

	void parseVariablesFromRaw();

	void update();
	void buildCommandString();
	void buildDisplayString();
public:
	IRCMessage(const QByteArray& raw);
	IRCMessage(const QString& string);
	IRCMessage(const QString& type, const QString& text);

	void setChannel(const QString& channel);
	void setMessage(const QString& newMessage);
	void setSentBy(const QString& who);

	QString getMessageType() const;
	QDateTime getTimeStamp() const;
	QString getMessage() const;
	QString getSentBy() const;
	QString getChannel() const;

	QString getCommandString() const;
	QString getDisplayString() const;
};