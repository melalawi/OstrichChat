#include "ChannelFrame.h"

#include <QtNetwork>
#include <QSplitter>

#include "ChatLine.h"
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

	chatList = new QListWidget;
	userList = new QListWidget;

	// TODO: Not this
	chatList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	chatList->setWordWrap(true);
	chatList->setAlternatingRowColors(true);
	userList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	userList->setWordWrap(true);
	userList->setAlternatingRowColors(true);

	splitter->setContentsMargins(QMargins(0, 0, 2, 0));
	splitter->setStretchFactor(0, 2);

	splitter->addWidget(chatList);
	splitter->addWidget(userList);
}

void ChannelFrame::assignSlots() {
	//When the user wants to send a message
	connect(ui.chatSubmitButton, SIGNAL(clicked()), this, SLOT(messageSend()));
	connect(ui.chatTextEdit, SIGNAL(returnPressed()), this, SLOT(messageSend()));

	connect(channelConnection, SIGNAL(lineReceivedSignal(const QString&)), this, SLOT(onNewChatLineSlot(const QString&)));
	connect(channelConnection, SIGNAL(lineSentSignal(const QString&)), this, SLOT(onNewChatLineSlot(const QString&)));
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
	QString stringToSend = ui.chatTextEdit->toPlainText().simplified();

	if (stringToSend.length() > 0) {
		channelConnection->sendPRIVMSG(stringToSend);

		ui.chatTextEdit->clear();
	}
}

// Called whenever a new line of chat is received
void ChannelFrame::onNewChatLineSlot(const QString& line) {
	ChatLine *nextLine = new ChatLine(QTime(3, 3, 3, 3), "tempUser", line);
	QListWidgetItem *item = new QListWidgetItem(line);


	chatList->addItem(item);
}

//namespace Ostrich
}