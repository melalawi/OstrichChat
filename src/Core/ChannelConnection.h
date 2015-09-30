#pragma once

#include <QtNetwork>
#include "IRCMessage.h"

class ServerConnection;

// Should this extend QObject?
class ChannelConnection : public QObject {
	Q_OBJECT

private:
    ServerConnection *parentSocket = nullptr;
    QString channelName;

	void assignSlots();

	// Sends commandString
	void IRCSendMessage(const IRCMessage& message);
public:
	ChannelConnection(const QString& channel, ServerConnection *parent = 0);
    ~ChannelConnection();

	QString getChannelName() const;

	void channelJoin();
	void channelLeave();

	void IRCSendString(const QString& string);// Generated IRCMessage from string to send
	void IRCReceiveString(const QString& string);
signals:
	void onMessageSent(const IRCMessage& string);
	void onMessageReceived(const IRCMessage& string);
};