#include "OstrichChat.h"

#include "ChannelWidget.h"
#include "ConnectDialog.h"

OstrichChat::OstrichChat(QWidget *parent) : QMainWindow(parent) {
    masterTabWidget = new QTabWidget;
    masterTabWidget->setTabsClosable(true);

    ui.setupUi(this);

    assignSlots();
}

void OstrichChat::assignSlots() {
    connect(masterTabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(destroyChannelTab(int)));
    connect(ui.actionConnectToChannel, SIGNAL(triggered()), this, SLOT(launchConnectPopup()));
}

OstrichChat::~OstrichChat() {
}

void OstrichChat::initialize() {
    show();
}

void OstrichChat::generateChannelTab(const QString& channelName) {
    ChannelWidget *newChannel = new ChannelWidget(channelName);

    if (centralWidget() != masterTabWidget) {
        this->setCentralWidget(masterTabWidget);
    }

    masterTabWidget->addTab(newChannel, channelName);

    newChannel->connectToChannel();
}

void OstrichChat::destroyChannelTab(int tabSlot) {
    ChannelWidget *channelTab = static_cast<ChannelWidget*>(masterTabWidget->widget(tabSlot));

    channelTab->disconnectFromChannel();

    masterTabWidget->removeTab(tabSlot);
}

void OstrichChat::launchConnectPopup() {
    connectDialog = new ConnectDialog(this);

    //Assign the slot to the channel
    connect(connectDialog, SIGNAL(connectToChannel(const QString&)), this, SLOT(generateChannelTab(const QString&)));

    connectDialog->initialize();
}