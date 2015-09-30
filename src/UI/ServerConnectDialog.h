#pragma once

#include <QDialog>

#include "ui_ServerConnectDialog.h"

class ServerConnectDialog : public QDialog {
    Q_OBJECT

private:
    Ui::ServerConnectDialog ui;

    void assignSlots();
public:
    ServerConnectDialog(QWidget *parent = 0);
    ~ServerConnectDialog();

    void initialize();

private slots:
	void on_manualLoginButton_clicked();
    void checkManualCredentials();

signals:
	void connectUser(const QString& user, const QString& oauth);
};
