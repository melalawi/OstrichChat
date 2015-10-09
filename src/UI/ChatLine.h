#pragma once

#include <QTime>
#include <QString>

#include "ui_ChatLine.h"

namespace Ostrich {

class ChatLine : public QFrame {
	Q_OBJECT

private:
	Ui::ChatLine ui;

	void assignSlots();

public:
	ChatLine(const QTime& time, const QString& user, const QString& message, QFrame *parent = 0);
	~ChatLine();

};

//namespace Ostrich
}