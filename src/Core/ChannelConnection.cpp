#include "ChannelConnection.h"

const QString TWITCH_HOST = "irc.twitch.tv";
const int TWITCH_PORT = 6667;

const QRegularExpression PRIVMSG_MATCH("PRIVMSG");
const QRegularExpression USERNAME_MATCH("\\:(.*)\\!");

ChannelConnection::ChannelConnection(QObject *parent) : QTcpSocket(parent) {
    assignSlots();
}

ChannelConnection::~ChannelConnection() {
}

void ChannelConnection::assignSlots() {
    connect(this, SIGNAL(readyRead()), this, SLOT(analyseMessage()));
}

void ChannelConnection::connectToChannel(const QString& channel, const QString& user, const QString& oauth) {
    channelName = "#" + channel;
    channelMatch.setPattern("PRIVMSG/s" + channelName + ":/s(.*?)");

    connectToHost(TWITCH_HOST, TWITCH_PORT);

    // TODO: Wait until connection established

    //Send various assign commands
    writeQString(QString("PASS " + oauth));
    writeQString(QString("NICK " + user));
    writeQString(QString("JOIN " + channelName));
}

void ChannelConnection::disconnectFromChannel() {
    disconnectFromHost();
}

void ChannelConnection::analyseMessage() {
    QByteArray next;
    QString nextLine;
    QString parsed;

    do {
        next = readLine();
        nextLine = QString(next);

        if (PRIVMSG_MATCH.match(nextLine).hasMatch()) {
            parsed = USERNAME_MATCH.match(nextLine).captured(0) + ": " + channelMatch.match(nextLine).captured(0);

            emit messageReceived(parsed);
        }

    } while (next.length());
}

void ChannelConnection::sendIRCMessage(const QString& message) {
    QString finalMessage = QString("PRIVMSG " + channelName + " :" + message);

    writeQString(finalMessage);
}

void ChannelConnection::writeQString(const QString& message) {
    std::string stringified = message.toStdString() + "\r\n";

    write(stringified.c_str());
    flush();
}