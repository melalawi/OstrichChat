#pragma once

#include <QWidget>

#include "../Core/ChannelConnection.h"

#include "ui_ChannelWidget.h"

class ChannelWidget : public QWidget {
    Q_OBJECT

private:
    Ui::ChannelWidget ui;

    QString channelName;
    ChannelConnection *channelConnection;

    void assignSlots();
public:
    ChannelWidget(const QString& channel, QWidget *parent = 0);
    ~ChannelWidget();

    void connectToChannel();
    void disconnectFromChannel();

private slots:
    void sendMessage();
    void receiveMessage(const QString& message);
};
