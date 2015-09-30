#pragma once

#include <QWidget>
#include <vector>

#include "ui_OstrichChat.h"

class ServerWidget;
class ServerConnectDialog;

class OstrichChat : public QMainWindow {
    Q_OBJECT

private:
    Ui::OstrichChatWindow ui;

    std::vector<ServerWidget*> serverWidgets;
    ServerConnectDialog *twitchConnectDialog = nullptr;

    void assignSlots();

public:
    OstrichChat(QWidget *parent = 0);
    ~OstrichChat();

    void initialize();

	void setSubtitle(const QString& text);

private slots:
    void twitchConnect();

	void connectNewUser(const QString& user, const QString& oauth);
	void disconnectUser(const QString& user);

	void joinChannel();
};
