#pragma once

#include <QStyledItemDelegate>
#include <QTextDocument>
#include <QPainter>
#include <QObject>
#include <QTime>
#include <QString>

namespace Ostrich {

class ChatLine : public QStyledItemDelegate {
	Q_OBJECT

private:
	QTextOption *textOption;
	QTextDocument *document;

public:
	// Explicit constructor: No implicit conversions of parameters are made
	// If you don't give the constructor exactly what it wants, it yells at you
	explicit ChatLine(QObject *parent = 0);
	~ChatLine();

	// Virtual functions specified by Qt
	void paint(QPainter *painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
	QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;

};

//namespace Ostrich
}