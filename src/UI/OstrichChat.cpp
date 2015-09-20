#include "OstrichChat.h"

#include "ChannelWidget.h"
#include "ConnectDialog.h"

#include <QWidget>

OstrichChat::OstrichChat(QWidget *parent) : QMainWindow(parent) {
    masterTabWidget = new QTabWidget;

    ui.setupUi(this);
}

OstrichChat::~OstrichChat() {
}

void OstrichChat::initialize() {
    show();

    launchConnectPopup();
}

void OstrichChat::addChannel() {
    ChannelWidget *channelUI = new ChannelWidget(this);

    //if (&(this->centralWidget) != masterTabWidget) {
        this->setCentralWidget(masterTabWidget);
    //}

    masterTabWidget->addTab(channelUI, "#channelName");
}

void OstrichChat::launchConnectPopup() {
    ConnectDialog connectDialog(this);

    connectDialog.show();

    connectDialog.exec();
}