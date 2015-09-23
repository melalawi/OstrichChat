#pragma once

#include <QtNetwork>

class ChannelConnection : public QTcpSocket {
    Q_OBJECT

private:
    QString channelName;
    QBuffer *bufferReader;

    QRegularExpression channelMatch;

    void assignSlots();
    void writeQString(const QString& message);
public:
    ChannelConnection(QObject *parent = 0);
    ~ChannelConnection();

    void connectToChannel(const QString& channel, const QString& user, const QString& oauth);
    void disconnectFromChannel();

    void sendIRCMessage(const QString& message);

private slots:
    void analyseMessage();

signals:
    // TODO: Contain the message in a separate object
    void messageReceived(const QString&);
};