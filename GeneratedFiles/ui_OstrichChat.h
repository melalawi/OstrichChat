/********************************************************************************
** Form generated from reading UI file 'OstrichChat.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSTRICHCHAT_H
#define UI_OSTRICHCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OstrichChatWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionConnectToChannel;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuOstrichChat;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *OstrichChatWindow)
    {
        if (OstrichChatWindow->objectName().isEmpty())
            OstrichChatWindow->setObjectName(QStringLiteral("OstrichChatWindow"));
        OstrichChatWindow->resize(411, 857);
        OstrichChatWindow->setMinimumSize(QSize(411, 0));
        actionExit = new QAction(OstrichChatWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setIconVisibleInMenu(false);
        actionAbout = new QAction(OstrichChatWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionConnectToChannel = new QAction(OstrichChatWindow);
        actionConnectToChannel->setObjectName(QStringLiteral("actionConnectToChannel"));
        centralWidget = new QWidget(OstrichChatWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        OstrichChatWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OstrichChatWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 411, 21));
        menuBar->setNativeMenuBar(false);
        menuOstrichChat = new QMenu(menuBar);
        menuOstrichChat->setObjectName(QStringLiteral("menuOstrichChat"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        OstrichChatWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(OstrichChatWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OstrichChatWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(OstrichChatWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        OstrichChatWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuOstrichChat->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuOstrichChat->addAction(actionConnectToChannel);
        menuOstrichChat->addSeparator();
        menuOstrichChat->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(OstrichChatWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), OstrichChatWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(OstrichChatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OstrichChatWindow)
    {
        OstrichChatWindow->setWindowTitle(QApplication::translate("OstrichChatWindow", "OstrichChat", 0));
        actionExit->setText(QApplication::translate("OstrichChatWindow", "Exit", 0));
        actionExit->setIconText(QApplication::translate("OstrichChatWindow", "Exit", 0));
        actionAbout->setText(QApplication::translate("OstrichChatWindow", "About", 0));
        actionConnectToChannel->setText(QApplication::translate("OstrichChatWindow", "Connect to Channel", 0));
        menuOstrichChat->setTitle(QApplication::translate("OstrichChatWindow", "OstrichChat", 0));
        menuHelp->setTitle(QApplication::translate("OstrichChatWindow", "Help", 0));
        toolBar->setWindowTitle(QApplication::translate("OstrichChatWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class OstrichChatWindow: public Ui_OstrichChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSTRICHCHAT_H
