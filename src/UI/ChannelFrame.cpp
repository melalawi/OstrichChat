#include "ChannelFrame.h"

#include <QtNetwork>
#include <QSplitter>
#include <QScrollBar>

#include "ChatSubmitBox.h"
#include "ChatLine.h"
#include "ChatList.h"
#include "UserList.h"
#include "../Core/ChannelConnection.h"

namespace Ostrich {

ChannelFrame::ChannelFrame(const QString& name, ChannelConnection *channel, QWidget *parent) : QFrame(parent) {
	channelName = name;
	channelConnection = channel;

	setupUI();
	assignSlots();
}

ChannelFrame::~ChannelFrame() {}

// Adds chat and user lists, splitter, etc
void ChannelFrame::setupUI() {
	ui.setupUi(this);
	QSplitter *splitter = new QSplitter(Qt::Horizontal);
	
	ui.bodyWidgetLayout->addWidget(splitter);// Splitter goes in body widget

	chatList = new ChatList;
	userList = new UserList;
	chatBox = new ChatSubmitBox;

	ui.footerContainer->insertWidget(0, chatBox);

	chatList->setItemDelegate(new ChatLine(chatList));

	splitter->setContentsMargins(QMargins(0, 0, 2, 0));
	splitter->setStretchFactor(0, 2);

	splitter->addWidget(chatList);
	splitter->addWidget(userList);
}

void ChannelFrame::assignSlots() {
	//When the user wants to send a message
	connect(ui.chatSubmitButton, SIGNAL(clicked()), this, SLOT(messageSend()));
	connect(chatBox, SIGNAL(onReturnPressed()), this, SLOT(messageSend()));

	// Called whenever a new line of chat is received
	connect(channelConnection, SIGNAL(lineReceivedSignal(const QString&)), chatList, SLOT(addChatLine(const QString&)));
	connect(channelConnection, SIGNAL(lineSentSignal(const QString&)), chatList, SLOT(addChatLine(const QString&)));
}


void ChannelFrame::channelJoin() {
	channelConnection->channelJoin();
}

void ChannelFrame::channelLeave() {
	channelConnection->channelLeave();
}

// Slots
void ChannelFrame::messageSend() {
	// TODO: Check if message is valid before sending (not sending blanks)
	QString stringToSend = chatBox->emptyChatBox();

	if (stringToSend.length() > 0) {
		channelConnection->sendPRIVMSG(stringToSend);
	}
}

//namespace Ostrich
}