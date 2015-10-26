#include "ChatList.h"

#include <QScrollBar>

namespace Ostrich {

const int MAX_CHATLINE_COUNT = 100;

ChatList::ChatList(QWidget *parent) : QListWidget(parent) {
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setWordWrap(true);
	setAlternatingRowColors(true);

	connect(verticalScrollBar(), SIGNAL(rangeChanged(int, int)), this, SLOT(onRangeChange(int, int)));
}

ChatList::~ChatList() {}

void ChatList::emptyChat() {
}

// Public slots
// Called whenever a new line of chat is received
// TODO: Ignore users, etc
void ChatList::addChatLine(const QString &line) {
	addItem(line);
}

// Private slots
void ChatList::onRangeChange(int min, int max) {
	verticalScrollBar()->setValue(max);
}

//namespace Ostrich
}