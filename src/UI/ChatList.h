#pragma once

#include <QListWidget>
#include <QList>
#include <QString>

namespace Ostrich {

// ChatBox used to talk in chat. Pressing the up key will allow you to scroll through previous posts.
// TODO: Containment instead of inheritance
class ChatList : public QListWidget {
	Q_OBJECT

private:
	bool scrollToBottom;

public:
	ChatList(QWidget *parent = 0);
	~ChatList();

	void emptyChat();

public slots:
	void addChatLine(const QString &string);

private slots:
	void onRangeChange(int min, int max);
};

//namespace Ostrich
}