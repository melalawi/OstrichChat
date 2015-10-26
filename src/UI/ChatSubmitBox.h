#pragma once

#include <QTextEdit>
#include <QList>
#include <QString>
#include <QKeyEvent>

namespace Ostrich {

// ChatBox used to talk in chat. Pressing the up key will allow you to scroll through previous posts.
// TODO: Containment instead of inheritance
class ChatSubmitBox : public QTextEdit {
	Q_OBJECT

private:
	QList<QString> chatHistory;

	void scrollChatHistory(bool direction);
	QString getMessageAt(unsigned int index);
public:
	ChatSubmitBox(QWidget *parent = 0);
	~ChatSubmitBox();

	QString emptyChatBox();

	// Virtual implementation
	void keyPressEvent(QKeyEvent *e);

signals:
	void onReturnPressed();

};

//namespace Ostrich
}