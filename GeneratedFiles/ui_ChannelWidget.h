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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChannelWidget
{
public:
    QGridLayout *gridLayout;
    QWidget *centralGridLayout;
    QGridLayout *centralGridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayoutTop;
    QTextBrowser *chatLines;
    QTextBrowser *userList;
    QHBoxLayout *horizontalLayoutBottom;
    QLineEdit *chatTextArea;
    QToolButton *emoteButton;
    QPushButton *chatSubmitButton;

    void setupUi(QWidget *ChannelWidget)
    {
        if (ChannelWidget->objectName().isEmpty())
            ChannelWidget->setObjectName(QStringLiteral("ChannelWidget"));
        ChannelWidget->resize(945, 902);
        gridLayout = new QGridLayout(ChannelWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        centralGridLayout = new QWidget(ChannelWidget);
        centralGridLayout->setObjectName(QStringLiteral("centralGridLayout"));
        centralGridLayout_2 = new QGridLayout(centralGridLayout);
        centralGridLayout_2->setSpacing(0);
        centralGridLayout_2->setObjectName(QStringLiteral("centralGridLayout_2"));
        centralGridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayoutTop = new QHBoxLayout();
        horizontalLayoutTop->setSpacing(1);
        horizontalLayoutTop->setObjectName(QStringLiteral("horizontalLayoutTop"));
        chatLines = new QTextBrowser(centralGridLayout);
        chatLines->setObjectName(QStringLiteral("chatLines"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chatLines->sizePolicy().hasHeightForWidth());
        chatLines->setSizePolicy(sizePolicy);

        horizontalLayoutTop->addWidget(chatLines);

        userList = new QTextBrowser(centralGridLayout);
        userList->setObjectName(QStringLiteral("userList"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(userList->sizePolicy().hasHeightForWidth());
        userList->setSizePolicy(sizePolicy1);

        horizontalLayoutTop->addWidget(userList);


        verticalLayout->addLayout(horizontalLayoutTop);

        horizontalLayoutBottom = new QHBoxLayout();
        horizontalLayoutBottom->setSpacing(5);
        horizontalLayoutBottom->setObjectName(QStringLiteral("horizontalLayoutBottom"));
        chatTextArea = new QLineEdit(centralGridLayout);
        chatTextArea->setObjectName(QStringLiteral("chatTextArea"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(chatTextArea->sizePolicy().hasHeightForWidth());
        chatTextArea->setSizePolicy(sizePolicy2);

        horizontalLayoutBottom->addWidget(chatTextArea);

        emoteButton = new QToolButton(centralGridLayout);
        emoteButton->setObjectName(QStringLiteral("emoteButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(emoteButton->sizePolicy().hasHeightForWidth());
        emoteButton->setSizePolicy(sizePolicy3);

        horizontalLayoutBottom->addWidget(emoteButton);

        chatSubmitButton = new QPushButton(centralGridLayout);
        chatSubmitButton->setObjectName(QStringLiteral("chatSubmitButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(chatSubmitButton->sizePolicy().hasHeightForWidth());
        chatSubmitButton->setSizePolicy(sizePolicy4);

        horizontalLayoutBottom->addWidget(chatSubmitButton);


        verticalLayout->addLayout(horizontalLayoutBottom);


        centralGridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout->addWidget(centralGridLayout, 0, 1, 1, 1);


        retranslateUi(ChannelWidget);

        QMetaObject::connectSlotsByName(ChannelWidget);
    } // setupUi

    void retranslateUi(QWidget *ChannelWidget)
    {
        ChannelWidget->setWindowTitle(QApplication::translate("ChannelWidget", "Form", 0));
        emoteButton->setText(QApplication::translate("ChannelWidget", "...", 0));
        chatSubmitButton->setText(QApplication::translate("ChannelWidget", "Chat", 0));
    } // retranslateUi

};

namespace Ui {
    class ChannelWidget: public Ui_ChannelWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNELWIDGET_H
