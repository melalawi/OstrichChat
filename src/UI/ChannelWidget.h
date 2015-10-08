#pragma once

#include <QWidget>

#include "ui_ChannelWidget.h"

namespace Ostrich {

// Forward declarations
class ChannelConnection;

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

signals:
	void processStringForOutput(const QString& text);

private slots:
	void messageSend();
	void onNewChatLineSlot(const QString& line);

};

//namespace Ostrich
}
