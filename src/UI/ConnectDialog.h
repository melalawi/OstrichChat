#pragma once

#include <QDialog>

#include "ui_ConnectDialog.h"

class ConnectDialog : public QDialog {
    Q_OBJECT

private:
    Ui::ConnectDialog ui;

    void assignSlots();
public:
    ConnectDialog(QWidget *parent = 0);
    ~ConnectDialog();

    void initialize();

private slots:
    void on_connectButton_clicked();
    void checkChannelLineInput(const QString& lineText);

signals:
    void connectToChannel(const QString& channelName);
};
