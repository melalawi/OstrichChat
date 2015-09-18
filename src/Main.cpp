#include "UI/OstrichChat.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    int exitCode = 0;
    QApplication application(argc, argv);
    OstrichChat mainWindow;

    mainWindow.show();

    exitCode = application.exec();

    return exitCode;
}
