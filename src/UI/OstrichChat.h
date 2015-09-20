#pragma once

#include <QWidget>
#include "ui_OstrichChat.h" // Point this to the parent folder for some reason

class OstrichChat : public QMainWindow {
    Q_OBJECT

private:
    Ui::OstrichChatWindow ui;
    QTabWidget *masterTabWidget;

    void launchConnectPopup();
public:
    OstrichChat(QWidget *parent = 0);
    ~OstrichChat();

    void initialize();

    void addChannel();
};
