#include "ChannelWidget.h"

#include <QtNetwork>
#include "../Core/ChannelConnection.h"

namespace Ostrich {

ChannelWidget::ChannelWidget(const QString& name, ChannelConnection *channel, QWidget *parent) : QWidget(parent) {
	channelName = name;
	channelConnection = channel;

	ui.setupUi(this);

	assignSlots();
}

ChannelWidget::~ChannelWidget() {

}

void ChannelWidget::assignSlots() {
	//When the user wants to send a message
	connect(ui.chatSubmitButton, SIGNAL(clicked()), this, SLOT(messageSend()));
	connect(ui.chatTextArea, SIGNAL(returnPressed()), this, SLOT(messageSend()));

	connect(channelConnection, SIGNAL(onMessageReceived(const IRCMessage&)), this, SLOT(addChatLine(const IRCMessage&)));
	connect(channelConnection, SIGNAL(onMessageSent(const IRCMessage&)), this, SLOT(addChatLine(const IRCMessage&)));
}


void ChannelWidget::channelJoin() {
	channelConnection->channelJoin();
}

void ChannelWidget::channelLeave() {
	channelConnection->channelLeave();
}

// Slots
void ChannelWidget::messageSend() {
	// TODO: Check if message is valid before sending
	QString text = ui.chatTextArea->text();

	channelConnection->IRCSendString(text);

	ui.chatTextArea->clear();
}

void ChannelWidget::addChatLine(const IRCMessage& message) {
	ui.chatLines->append(message.getDisplayString());
}

//namespace Ostrich
}