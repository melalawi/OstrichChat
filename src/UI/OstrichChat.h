#pragma once

#include <QWidget>
#include "ui_OstrichChat.h"

#include "ConnectDialog.h"

class OstrichChat : public QMainWindow {
    Q_OBJECT

private:
    Ui::OstrichChatWindow ui;

    QTabWidget *masterTabWidget = nullptr;
    ConnectDialog *connectDialog = nullptr;

    void assignSlots();

public:
    OstrichChat(QWidget *parent = 0);
    ~OstrichChat();

    void initialize();

private slots:
    void generateChannelTab(const QString& channelName);
    void destroyChannelTab(int tabSlot);
    void launchConnectPopup();
};
