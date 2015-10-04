#pragma once

#include <QWidget>

#include "ui_ChannelWidget.h"

namespace Ostrich {

// Forward declarations
class ChannelConnection; 
class IRCMessage;

class ChannelWidget : public QWidget {
	Q_OBJECT

private:
	Ui::ChannelWidget ui;

	QString channelName;
	ChannelConnection *channelConnection;

	void assignSlots();

public:
	ChannelWidget(const QString& name, ChannelConnection *channel, QWidget *parent = 0);
	~ChannelWidget();

	void channelJoin();
	void channelLeave();

private slots:
	void messageSend();
	void addChatLine(const IRCMessage& message);
};

//namespace Ostrich
}
