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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OstrichChatWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionTwitchConnect;
    QAction *actionJoinChannel;
    QAction *actionOptions;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *centralGridLayout;
    QLabel *subtitleLabel;
    QGridLayout *subcontentGridLayout;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuOstrichChat;
    QMenu *menuHelp;
    QMenu *menuSettings;
    QMenu *menuChannels;

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
        actionTwitchConnect = new QAction(OstrichChatWindow);
        actionTwitchConnect->setObjectName(QStringLiteral("actionTwitchConnect"));
        actionJoinChannel = new QAction(OstrichChatWindow);
        actionJoinChannel->setObjectName(QStringLiteral("actionJoinChannel"));
        actionOptions = new QAction(OstrichChatWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        centralWidget = new QWidget(OstrichChatWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        centralGridLayout = new QGridLayout();
        centralGridLayout->setSpacing(6);
        centralGridLayout->setObjectName(QStringLiteral("centralGridLayout"));
        subtitleLabel = new QLabel(centralWidget);
        subtitleLabel->setObjectName(QStringLiteral("subtitleLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(subtitleLabel->sizePolicy().hasHeightForWidth());
        subtitleLabel->setSizePolicy(sizePolicy);
        subtitleLabel->setMaximumSize(QSize(16777215, 25));

        centralGridLayout->addWidget(subtitleLabel, 0, 0, 1, 1, Qt::AlignTop);

        subcontentGridLayout = new QGridLayout();
        subcontentGridLayout->setSpacing(6);
        subcontentGridLayout->setObjectName(QStringLiteral("subcontentGridLayout"));

        centralGridLayout->addLayout(subcontentGridLayout, 1, 0, 1, 1);


        gridLayout_2->addLayout(centralGridLayout, 0, 0, 1, 1);

        OstrichChatWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(OstrichChatWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        OstrichChatWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(OstrichChatWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 411, 21));
        menuBar->setNativeMenuBar(false);
        menuOstrichChat = new QMenu(menuBar);
        menuOstrichChat->setObjectName(QStringLiteral("menuOstrichChat"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuChannels = new QMenu(menuBar);
        menuChannels->setObjectName(QStringLiteral("menuChannels"));
        OstrichChatWindow->setMenuBar(menuBar);

        menuBar->addAction(menuOstrichChat->menuAction());
        menuBar->addAction(menuChannels->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuOstrichChat->addAction(actionTwitchConnect);
        menuOstrichChat->addSeparator();
        menuOstrichChat->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuSettings->addAction(actionOptions);
        menuChannels->addAction(actionJoinChannel);

        retranslateUi(OstrichChatWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), OstrichChatWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(OstrichChatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OstrichChatWindow)
    {
        OstrichChatWindow->setWindowTitle(QApplication::translate("OstrichChatWindow", "OstrichChat", 0));
        actionExit->setText(QApplication::translate("OstrichChatWindow", "&Exit", 0));
        actionExit->setIconText(QApplication::translate("OstrichChatWindow", "Exit", 0));
        actionAbout->setText(QApplication::translate("OstrichChatWindow", "&About", 0));
        actionTwitchConnect->setText(QApplication::translate("OstrichChatWindow", "&Login to Twitch.tv", 0));
        actionJoinChannel->setText(QApplication::translate("OstrichChatWindow", "&Join A Channel", 0));
        actionOptions->setText(QApplication::translate("OstrichChatWindow", "&Options", 0));
        subtitleLabel->setText(QApplication::translate("OstrichChatWindow", "You are not connected!", 0));
        toolBar->setWindowTitle(QApplication::translate("OstrichChatWindow", "toolBar", 0));
        menuOstrichChat->setTitle(QApplication::translate("OstrichChatWindow", "OstrichChat", 0));
        menuHelp->setTitle(QApplication::translate("OstrichChatWindow", "Help", 0));
        menuSettings->setTitle(QApplication::translate("OstrichChatWindow", "&Settings", 0));
        menuChannels->setTitle(QApplication::translate("OstrichChatWindow", "Channels", 0));
    } // retranslateUi

};

namespace Ui {
    class OstrichChatWindow: public Ui_OstrichChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSTRICHCHAT_H
