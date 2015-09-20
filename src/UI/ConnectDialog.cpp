#include "ConnectDialog.h"

#include "OstrichChat.h"

#include <iostream>

ConnectDialog::ConnectDialog(QWidget *parent) : QDialog(parent) {
    ostrichChat = (OstrichChat*)parent;
    ui.setupUi(this);

    // When you click on the connect button, generate the channel tab and attempt to connect to it
    connect(ui.connectButton, SIGNAL(clicked()), this, SLOT(on_connectButton_clicked()));
}

ConnectDialog::~ConnectDialog() {
}

void ConnectDialog::on_connectButton_clicked() {
    if (ostrichChat) {
        ostrichChat->addChannel();
    }
}
