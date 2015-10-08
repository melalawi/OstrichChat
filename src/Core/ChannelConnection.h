#pragma once

#include <QtNetwork>
#include "IRCMessage.h"

namespace Ostrich {

class ServerConnection;

// Should this extend QObject?
class ChannelConnection : public QObject {
	Q_OBJECT

private:
    ServerConnection *parentSocket = nullptr;
    QString channelName;

	void assignSlots();
public:
	ChannelConnection(const QString& channel, ServerConnection *parent = 0);
    ~ChannelConnection();

	QString getChannelName() const;

	void channelJoin();
	void channelLeave();

	// Only called by widget, chat line contents go here
	void sendPRIVMSG(const QString& string);

	void IRCSendMessage(IRCMessage message);// Generated IRCMessage from string to send
	void IRCReceiveMessage(const IRCMessage& message);

	// Does not display the message in chat
	void IRCSendSilent(IRCMessage message);

signals:
	void messageSentSignal(const IRCMessage& message);
	void messageReceivedSignal(const IRCMessage& message);

	// QString-only variants for above fire at the same time, for widgets to use (best not to tell widgets about IRCMessage object
	void lineSentSignal(const QString& line);
	void lineReceivedSignal(const QString& line);
};

//namespace Ostrich
}