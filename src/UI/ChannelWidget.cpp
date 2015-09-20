#include "ChannelWidget.h"

#include <QtNetwork>

ChannelWidget::ChannelWidget(QWidget *parent) : QWidget(parent) {
    ui.setupUi(this);

    channelSocket = new QTcpSocket(this);
}

ChannelWidget::~ChannelWidget() {

}


void ChannelWidget::connectToServer() {
    QTcpSocket *socket;
}