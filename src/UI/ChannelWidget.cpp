#include "ChannelWidget.h"

#include <QtNetwork>

ChannelWidget::ChannelWidget(const QString& channel, QWidget *parent) : QWidget(parent) {
    channelName = channel;
    channelConnection = new ChannelConnection(this);

    ui.setupUi(this);

    assignSlots();
}

ChannelWidget::~ChannelWidget() {

}

void ChannelWidget::assignSlots() {
    //When the user wants to send a message
    connect(ui.chatSubmitButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(ui.chatTextArea, SIGNAL(returnPressed()), this, SLOT(sendMessage()));

    connect(channelConnection, SIGNAL(messageReceived(const QString&)), this, SLOT(receiveMessage(const QString&)));
}


void ChannelWidget::connectToChannel() {
    channelConnection->connectToChannel(channelName, QString("Ostrich_Bot"), QString("oauth:hy2vnkk8hjwvs0ptwjikdor7kq7t68"));
}

void ChannelWidget::disconnectFromChannel() {
    channelConnection->disconnectFromChannel();
}

void ChannelWidget::sendMessage() {
    // TODO: Check if message is valid before sending
    QString messageToSend = ui.chatTextArea->text();

    channelConnection->sendIRCMessage(messageToSend);

    ui.chatTextArea->clear();
}

void ChannelWidget::receiveMessage(const QString& message) {
    ui.chatLines->append(message);
}