#include "OstrichChat.h"

#include "ServerWidget.h"
#include "ServerConnectDialog.h"

OstrichChat::OstrichChat(QWidget *parent) : QMainWindow(parent) {
    ui.setupUi(this);

    assignSlots();
}

void OstrichChat::assignSlots() {
    connect(ui.actionTwitchConnect, SIGNAL(triggered()), this, SLOT(twitchConnect()));

	//Temporary
	connect(ui.actionJoinChannel, SIGNAL(triggered()), this, SLOT(joinChannel()));
}

OstrichChat::~OstrichChat() {
}

void OstrichChat::initialize() {
    show();
}

void OstrichChat::setSubtitle(const QString& text) {
	QLabel *subtitle = ui.centralWidget->findChild<QLabel*>("subtitleLabel");

	subtitle->setText(text);
}

// Launches the Twitch Login Dialog
void OstrichChat::twitchConnect() {
    twitchConnectDialog = new ServerConnectDialog(this);

    //Assign the slot to the channel
	connect(twitchConnectDialog, SIGNAL(connectUser(const QString&, const QString&)), this, SLOT(connectNewUser(const QString&, const QString&)));

    twitchConnectDialog->initialize();
}

// Initializes a new server widget for this particular user, then login + connect happens
// TODO: Check if this user is already connected
void OstrichChat::connectNewUser(const QString& user, const QString& oauth) {
	QGridLayout *gridLayout = ui.centralWidget->findChild<QGridLayout*>("subcontentGridLayout");
	ServerWidget *nextServerWidget = new ServerWidget(user, this);

	serverWidgets.push_back(nextServerWidget);

	gridLayout->addWidget(nextServerWidget);

	nextServerWidget->connectToServer(user, oauth);
}

// TODO
void OstrichChat::disconnectUser(const QString& user) {

}

void OstrichChat::joinChannel() {
	// TODO: Check if we're connected first
	// TODO: Better way
	if (serverWidgets.size()) {
		serverWidgets.at(0)->connectToChannel("insentience");
	}
}