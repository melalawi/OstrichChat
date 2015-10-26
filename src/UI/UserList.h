#pragma once

#include <QListWidget>
#include <QList>
#include <QString>

namespace Ostrich {

// List of Users in the specified chatroom
// TODO: Containment instead of inheritance
class UserList : public QListWidget {
	Q_OBJECT

private:
	QList<QString> usernames;

public:
	UserList(QWidget *parent = 0);
	~UserList();
};

//namespace Ostrich
}