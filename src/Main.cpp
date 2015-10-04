#include "UI/OstrichChat.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
	Ostrich::OstrichChat mainWindow;
	int exitCode = 0;

    mainWindow.initialize();

    exitCode = application.exec();

    return exitCode;
}
