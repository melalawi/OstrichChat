#pragma once

#include <QtNetwork>
#include <vector>

#include "IRCMessage.h"

namespace Ostrich {

class ChannelConnection;

class ServerConnection : public QTcpSocket {
    Q_OBJECT

private:
    QBuffer *bufferReader;

	bool isConnected;
	bool isLoggedIn;

	QString username;
	QString oAuthToken;

	std::vector<ChannelConnection*> channels;

    void assignSlots();

	void processInput(const QString& text);

	int getChannelIndex(const QString& channelName);

public:
    ServerConnection(QObject *parent = 0);
    ~ServerConnection();

	void twitchConnect(const QString& user, const QString& oauth);
	void twitchDisconnect();

	void removeChannelConnection(ChannelConnection *purge);
	void removeChannelConnection(const QString& channelName);
	ChannelConnection *addChannelConnection(const QString& channelName);
	ChannelConnection *getChannelConnection(const QString& channelName);

	QString getUser() const;

	// TODO: Use IRCMessage
	void outputString(const QString& text);

private slots:
	void sendMessageSlot(const IRCMessage& message);
	void processReadyRead();

public slots:
	void onServerConnection();
};

//namespace Ostrich
}