#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OstrichChat.h" // Point this to the parent folder for some reason

class OstrichChat : public QMainWindow {
    Q_OBJECT

private:
    Ui::OstrichChatClass ui;

public:
    OstrichChat(QWidget *parent = 0);
    ~OstrichChat();
};
