#pragma once

#include "ui_ServerWidget.h"

namespace Ostrich {

// Forward declarations
class OstrichChat;
class ServerConnection;

class ServerWidget : public QTabWidget {
	Q_OBJECT

private:
	Ui::ServerWidget ui;

	ServerConnection *serverConnection;

	void assignSlots();

public:
	ServerWidget(const QString& username, OstrichChat *parent);
	~ServerWidget();

	void connectToServer(const QString& user, const QString& oauth);
	void disconnectFromServer();

	void connectToChannel(const QString& channel);
	void disconnectFromChannel(const QString& channel);

private slots:
	void closeChannelTab(int tabIndex);
};

//namespace Ostrich
}