#pragma once

#include <memory>
#include <QWidget>
#include <QtNetwork>

#include "ui_ChannelWidget.h"

class ChannelWidget : public QWidget {
    Q_OBJECT

private:
    Ui::ChannelWidget ui;

    QTcpSocket *channelSocket;

public:
    ChannelWidget(QWidget *parent = 0);
    ~ChannelWidget();

    void readData();
    void connectToServer();
    void disconnectFromServer();
};
