#pragma once

#include <QDialog>
#include "OstrichChat.h"
#include "ui_ConnectDialog.h"

class ConnectDialog : public QDialog {
    Q_OBJECT

private:
    OstrichChat *ostrichChat;
    Ui::ConnectDialog ui;

public:
    ConnectDialog(QWidget *parent = 0);
    ~ConnectDialog();

private slots:
    void on_connectButton_clicked();
};
