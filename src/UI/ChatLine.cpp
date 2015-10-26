#include "ChatLine.h"

#include <QDebug>

namespace Ostrich {

ChatLine::ChatLine(QObject *parent) : QStyledItemDelegate(parent) {
	document = new QTextDocument;

	// Set our text to wrap
	textOption = new QTextOption(document->defaultTextOption());
	textOption->setWrapMode(QTextOption::WordWrap);

	document->setDefaultTextOption(*textOption);
}

ChatLine::~ChatLine() {}

// Our custom delegate paint function
// This tells our QListWidget how each chat line is drawn (text, emotes, urls, etc)
void ChatLine::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const {

	// Save the painter's state in the beginning (?)
	painter->save();

	// Send the painter to the position of this ChatLine
	painter->translate(option.rect.left(), option.rect.top());

	// Draw our rich text using our aligned painter
	document->setTextWidth(option.rect.width());
	document->setHtml(index.data().toString());
	document->drawContents(painter);

	// Restore the painter to the default location (?)
	painter->restore();
}

QSize ChatLine::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const {
	return QStyledItemDelegate::sizeHint(option, index);
}

//namespace Ostrich
}