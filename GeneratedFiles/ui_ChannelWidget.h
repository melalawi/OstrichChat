/********************************************************************************
** Form generated from reading UI file 'ChannelWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNELWIDGET_H
#define UI_CHANNELWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChannelWidget
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *chatLines;
    QPushButton *chatSubmitButton;
    QLineEdit *chatTextArea;
    QToolButton *toolButton;
    QTextBrowser *userList;

    void setupUi(QWidget *ChannelWidget)
    {
        if (ChannelWidget->objectName().isEmpty())
            ChannelWidget->setObjectName(QStringLiteral("ChannelWidget"));
        ChannelWidget->resize(686, 770);
        gridLayout = new QGridLayout(ChannelWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        chatLines = new QTextBrowser(ChannelWidget);
        chatLines->setObjectName(QStringLiteral("chatLines"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chatLines->sizePolicy().hasHeightForWidth());
        chatLines->setSizePolicy(sizePolicy);

        gridLayout->addWidget(chatLines, 0, 0, 1, 1);

        chatSubmitButton = new QPushButton(ChannelWidget);
        chatSubmitButton->setObjectName(QStringLiteral("chatSubmitButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(chatSubmitButton->sizePolicy().hasHeightForWidth());
        chatSubmitButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(chatSubmitButton, 1, 2, 1, 1);

        chatTextArea = new QLineEdit(ChannelWidget);
        chatTextArea->setObjectName(QStringLiteral("chatTextArea"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(chatTextArea->sizePolicy().hasHeightForWidth());
        chatTextArea->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(chatTextArea, 1, 0, 1, 1);

        toolButton = new QToolButton(ChannelWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(toolButton, 1, 1, 1, 1);

        userList = new QTextBrowser(ChannelWidget);
        userList->setObjectName(QStringLiteral("userList"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(userList->sizePolicy().hasHeightForWidth());
        userList->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(userList, 0, 1, 1, 2);


        retranslateUi(ChannelWidget);

        QMetaObject::connectSlotsByName(ChannelWidget);
    } // setupUi

    void retranslateUi(QWidget *ChannelWidget)
    {
        ChannelWidget->setWindowTitle(QApplication::translate("ChannelWidget", "Form", 0));
        chatSubmitButton->setText(QApplication::translate("ChannelWidget", "Chat", 0));
        toolButton->setText(QApplication::translate("ChannelWidget", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class ChannelWidget: public Ui_ChannelWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNELWIDGET_H
