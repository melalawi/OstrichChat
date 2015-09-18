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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OstrichChatClass
{
public:
    QAction *actionExit;
    QAction *action_Exit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuOstrichChat;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OstrichChatClass)
    {
        if (OstrichChatClass->objectName().isEmpty())
            OstrichChatClass->setObjectName(QStringLiteral("OstrichChatClass"));
        OstrichChatClass->resize(504, 896);
        actionExit = new QAction(OstrichChatClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setIconVisibleInMenu(false);
        action_Exit = new QAction(OstrichChatClass);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        centralWidget = new QWidget(OstrichChatClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        OstrichChatClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OstrichChatClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 504, 21));
        menuBar->setNativeMenuBar(false);
        menuOstrichChat = new QMenu(menuBar);
        menuOstrichChat->setObjectName(QStringLiteral("menuOstrichChat"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        OstrichChatClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(OstrichChatClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OstrichChatClass->setStatusBar(statusBar);

        menuBar->addAction(menuOstrichChat->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuOstrichChat->addAction(actionExit);

        retranslateUi(OstrichChatClass);
        QObject::connect(actionExit, SIGNAL(triggered()), OstrichChatClass, SLOT(close()));

        QMetaObject::connectSlotsByName(OstrichChatClass);
    } // setupUi

    void retranslateUi(QMainWindow *OstrichChatClass)
    {
        OstrichChatClass->setWindowTitle(QApplication::translate("OstrichChatClass", "OstrichChat", 0));
        actionExit->setText(QApplication::translate("OstrichChatClass", "Exit", 0));
        actionExit->setIconText(QApplication::translate("OstrichChatClass", "Exit", 0));
        action_Exit->setText(QApplication::translate("OstrichChatClass", "&Exit", 0));
        menuOstrichChat->setTitle(QApplication::translate("OstrichChatClass", "OstrichChat", 0));
        menuHelp->setTitle(QApplication::translate("OstrichChatClass", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class OstrichChatClass: public Ui_OstrichChatClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSTRICHCHAT_H
