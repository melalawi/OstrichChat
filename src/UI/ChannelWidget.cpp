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

	connect(channelConnection, SIGNAL(lineReceivedSignal(const QString&)), this, SLOT(onNewChatLineSlot(const QString&)));
	connect(channelConnection, SIGNAL(lineSentSignal(const QString&)), this, SLOT(onNewChatLineSlot(const QString&)));
}


void ChannelWidget::channelJoin() {
	channelConnection->channelJoin();
}

void ChannelWidget::channelLeave() {
	channelConnection->channelLeave();
}

// Slots
void ChannelWidget::messageSend() {
	// TODO: Check if message is valid before sending (not sending blanks)
	QString stringToSend = ui.chatTextArea->text().simplified();

	if (stringToSend.length() > 0) {
		channelConnection->sendPRIVMSG(stringToSend);

		ui.chatTextArea->clear();
	}
}

// Called whenever a new line of chat is received
void ChannelWidget::onNewChatLineSlot(const QString& line) {
	ui.chatLines->append(line);
}

//namespace Ostrich
}