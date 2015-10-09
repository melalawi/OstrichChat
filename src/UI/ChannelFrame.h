#pragma once

#include "ui_ChannelFrame.h"

#include <QListWidget>

namespace Ostrich {

// Forward declarations
class ChannelConnection;

class ChannelFrame : public QFrame {
	Q_OBJECT

private:
	Ui::ChannelFrame ui;
	QListWidget *chatList;
	QListWidget *userList;

	QString channelName;
	ChannelConnection *channelConnection;

	void setupUI();
	void assignSlots();
public:
	ChannelFrame(const QString& name, ChannelConnection *channel, QWidget *parent = 0);
	~ChannelFrame();

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
