#include "ChatSubmitBox.h"

#include <QDebug>

namespace Ostrich {

const QSize CHAT_SIZE(16777215, 32);
const int MAX_HISTORY_SIZE = 10;

ChatSubmitBox::ChatSubmitBox(QWidget *parent) : QTextEdit(parent) {
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setLineWrapMode(QTextEdit::WidgetWidth);

	this->setMaximumSize(CHAT_SIZE);
	this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
}

ChatSubmitBox::~ChatSubmitBox() {}

QString ChatSubmitBox::getMessageAt(unsigned int index) {
	QString result = "";

	if (index < chatHistory.length()) {
		result = chatHistory.at(index);
	}

	return result;
}

// Up/Down arrow keys scroll through chat history
void ChatSubmitBox::scrollChatHistory(bool direction) {
	QString currentChatText = toPlainText();
	QString nextChatText;
	unsigned int index = 0;

	if (direction == true) {
		index = chatHistory.length() - 1;
	} else {
		index = 1;
	}

	nextChatText = getMessageAt(index);

	qDebug() << "chat length before: " << QString::number(chatHistory.length());
	chatHistory.removeAt(index);


	chatHistory.prepend(nextChatText);
	qDebug() << "chat length after: " << QString::number(chatHistory.length());
	setText(nextChatText);
	

	if (currentChatText.length()) {
		chatHistory.prepend(currentChatText);
	}
}

QString ChatSubmitBox::emptyChatBox() {
	QString result = toPlainText().simplified();

	if (result.length()) {
		chatHistory.prepend(toPlainText());

		qDebug() << "--";

		for (int i = 0; i < chatHistory.length(); ++i) {
			qDebug() << chatHistory.at(i).simplified();
		}

		clear();
	}

	return result;
}

// Anything you type into this chatbox will fire this event
// We capture Return/Enter (to send a message) and the up arrow key (to browse through chat history)
void ChatSubmitBox::keyPressEvent(QKeyEvent *e) {
	if (e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter) {
		emit onReturnPressed();

		// "Accept" the event after we're done
		e->accept();
	} else if (e->key() == Qt::Key_Up || e->key() == Qt::Key_Down) {
		scrollChatHistory(e->key() == Qt::Key_Up);
	} else {
		// Otherwise, just pass the event up to be handled normally
		QTextEdit::keyPressEvent(e);
	}
}

//namespace Ostrich
}