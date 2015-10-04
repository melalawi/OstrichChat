#include "ServerConnectDialog.h"

#include <QSignalMapper>
#include <iostream>
#include "OstrichChat.h"

namespace Ostrich {

// Flags: Keep dialog on top, prevent dialog from being resized
const Qt::WindowFlags DIALOG_FLAGS = Qt::WindowStaysOnTopHint;// ^ ~Qt::WindowContextHelpButtonHint;

ServerConnectDialog::ServerConnectDialog(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	// TEMPORARY: auto-fills lines with manual credentials
	ui.usernameLine->setText("Ostrich_Bot");
	ui.oAuthTokenLine->setText("oauth:hy2vnkk8hjwvs0ptwjikdor7kq7t68");
	ui.manualLoginButton->setEnabled(true);
	// END TEMP

	assignSlots();
}

ServerConnectDialog::~ServerConnectDialog() {}

void ServerConnectDialog::assignSlots() {
	// Only enable the manual login button when appropriate text is found in both the username and OAuth lines
	connect(ui.usernameLine, SIGNAL(textChanged(const QString&)), this, SLOT(checkManualCredentials()));
	connect(ui.oAuthTokenLine, SIGNAL(textChanged(const QString&)), this, SLOT(checkManualCredentials()));

	// Return button should have the same effect as clicking on the login button
	connect(ui.usernameLine, SIGNAL(returnPressed()), this, SLOT(on_manualLoginButton_clicked()));
	connect(ui.oAuthTokenLine, SIGNAL(returnPressed()), this, SLOT(on_manualLoginButton_clicked()));
}

void ServerConnectDialog::initialize() {

	show();

	setWindowFlags(windowFlags() | DIALOG_FLAGS);

	setFixedSize(size().width(), size().height());

	exec();
}

// Simple check of both manual credential lines. If the 'wrong' info is found, then keep the login button disabled;
void ServerConnectDialog::checkManualCredentials() {
	QString username = ui.usernameLine->text(),
		oauth = ui.oAuthTokenLine->text();

	// TODO: Make this check more comprehensive
	bool enableLogin = username.length() && oauth.length();

	ui.manualLoginButton->setEnabled(enableLogin);
}

// Connect the user to the server on button click (double check if button is enabled because hitting return on the lineTexts calls this as well)
void ServerConnectDialog::on_manualLoginButton_clicked() {
	if (ui.manualLoginButton->isEnabled()) {
		emit connectUser(ui.usernameLine->text(), ui.oAuthTokenLine->text());

		close();
	}
}

//namespace Ostrich
}