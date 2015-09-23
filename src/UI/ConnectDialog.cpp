#include "ConnectDialog.h"

#include "OstrichChat.h"
#include <QSignalMapper>
#include <iostream>

ConnectDialog::ConnectDialog(QWidget *parent) : QDialog(parent) {
    ui.setupUi(this);

    assignSlots();
}

ConnectDialog::~ConnectDialog() {
}

void ConnectDialog::assignSlots() {
    // NOTE: on_buttonName_clicked is AUTOMATICALLY CONNECTED BY QT IF IT EXISTS
    // That is pretty awesome
    //connect(ui.connectButton, SIGNAL(clicked()), this, SLOT(on_connectButton_clicked()));

    // Only enable the connectButton when there is text in channelLine
    connect(ui.channelLine, SIGNAL(textChanged(const QString&)), this, SLOT(checkChannelLineInput(const QString&)));
}

void ConnectDialog::initialize() {
    Qt::WindowFlags flags = windowFlags() | Qt::WindowStaysOnTopHint;
    
    show();

    setWindowFlags(flags & ~Qt::WindowContextHelpButtonHint);

    setFixedSize(size().width(), size().height());

    exec();
}

void ConnectDialog::checkChannelLineInput(const QString& lineText) {
    lineText.length() ? ui.connectButton->setDisabled(false) : ui.connectButton->setDisabled(true);
}

void ConnectDialog::on_connectButton_clicked() {
    emit connectToChannel(ui.channelLine->text());

    close();
}