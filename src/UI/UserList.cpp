#include "UserList.h"

#include <QDebug>

namespace Ostrich {

UserList::UserList(QWidget *parent) : QListWidget(parent) {
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setWordWrap(true);
	this->setAlternatingRowColors(true);
}

UserList::~UserList() {}



//namespace Ostrich
}