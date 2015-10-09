#include "ServerWidget.h"

#include <QtWidgets>
#include "OstrichChat.h"
#include "ChannelFrame.h"

#include "../Core/ServerConnection.h"

namespace Ostrich {

// Set up a server widget: Display name, connection variables, closable tabs, etc
ServerWidget::ServerWidget(const QString& username, OstrichChat *parent) : QTabWidget(parent) {
	ui.setupUi(this);
	setTabsClosable(true);

	serverConnection = new ServerConnection(this);

	parent->setSubtitle("User: " + username);

	assignSlots();
}

ServerWidget::~ServerWidget() {}

void ServerWidget::assignSlots() {
	connect(this, SIGNAL(tabCloseRequested(int)), this, SLOT(closeChannelTab(int)));
}

void ServerWidget::connectToServer(const QString& user, const QString& oauth) {
	serverConnection->twitchConnect(user, oauth);

	// TODO: Wait until connected
}

void ServerWidget::disconnectFromServer() {
	serverConnection->twitchDisconnect();
}

// TODO: Check if Server is connected first
//		 Check if channel exists.
void ServerWidget::connectToChannel(const QString& channelName) {
	ChannelConnection *newChannel = serverConnection->addChannelConnection(channelName);
	ChannelFrame *newWidget = new ChannelFrame(channelName, newChannel, this);

	newWidget->channelJoin();

	newWidget->show();

	addTab(newWidget, channelName);
}

// TODO: Check if this is the only channel remaining. If so, disconnect entire server widget
void ServerWidget::disconnectFromChannel(const QString& channelName) {

}

void ServerWidget::closeChannelTab(int tabIndex) {
	ChannelFrame *channelTab = static_cast<ChannelFrame*>(widget(tabIndex));

	channelTab->channelLeave();

	removeTab(tabIndex);
}

//namespace Ostrich
}