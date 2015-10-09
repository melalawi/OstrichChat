#include "ChatLine.h"

namespace Ostrich {

ChatLine::ChatLine(const QTime& time, const QString& user, const QString& message, QFrame *parent) : QFrame(parent) {
	ui.setupUi(this);

	ui.timeLabel->setText(time.toString("hh:mm a"));
	ui.userLabel->setText(user);
	ui.tempChatMessageLabel->setText(message);
}

ChatLine::~ChatLine() {}

//namespace Ostrich
}