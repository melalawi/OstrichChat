/********************************************************************************
** Form generated from reading UI file 'ChannelFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNELFRAME_H
#define UI_CHANNELFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChannelFrame
{
public:
    QGridLayout *channelFrameLayout;
    QHBoxLayout *footerContainer;
    QPushButton *someButton;
    QPushButton *chatSubmitButton;
    QHBoxLayout *bodyContainer;
    QWidget *bodyWidget;
    QHBoxLayout *bodyWidgetLayout;
    QHBoxLayout *headerContainer;
    QLabel *channelTitleLabel;

    void setupUi(QFrame *ChannelFrame)
    {
        if (ChannelFrame->objectName().isEmpty())
            ChannelFrame->setObjectName(QStringLiteral("ChannelFrame"));
        ChannelFrame->resize(538, 800);
        ChannelFrame->setFrameShape(QFrame::StyledPanel);
        ChannelFrame->setFrameShadow(QFrame::Raised);
        channelFrameLayout = new QGridLayout(ChannelFrame);
        channelFrameLayout->setObjectName(QStringLiteral("channelFrameLayout"));
        channelFrameLayout->setContentsMargins(-1, -1, 7, -1);
        footerContainer = new QHBoxLayout();
        footerContainer->setObjectName(QStringLiteral("footerContainer"));
        someButton = new QPushButton(ChannelFrame);
        someButton->setObjectName(QStringLiteral("someButton"));
        someButton->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(someButton->sizePolicy().hasHeightForWidth());
        someButton->setSizePolicy(sizePolicy);
        someButton->setMaximumSize(QSize(48, 48));

        footerContainer->addWidget(someButton);

        chatSubmitButton = new QPushButton(ChannelFrame);
        chatSubmitButton->setObjectName(QStringLiteral("chatSubmitButton"));
        sizePolicy.setHeightForWidth(chatSubmitButton->sizePolicy().hasHeightForWidth());
        chatSubmitButton->setSizePolicy(sizePolicy);
        chatSubmitButton->setMaximumSize(QSize(48, 48));

        footerContainer->addWidget(chatSubmitButton);


        channelFrameLayout->addLayout(footerContainer, 3, 0, 1, 1);

        bodyContainer = new QHBoxLayout();
        bodyContainer->setSpacing(0);
        bodyContainer->setObjectName(QStringLiteral("bodyContainer"));
        bodyWidget = new QWidget(ChannelFrame);
        bodyWidget->setObjectName(QStringLiteral("bodyWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bodyWidget->sizePolicy().hasHeightForWidth());
        bodyWidget->setSizePolicy(sizePolicy1);
        bodyWidgetLayout = new QHBoxLayout(bodyWidget);
        bodyWidgetLayout->setSpacing(0);
        bodyWidgetLayout->setObjectName(QStringLiteral("bodyWidgetLayout"));
        bodyWidgetLayout->setContentsMargins(0, 0, 0, 0);

        bodyContainer->addWidget(bodyWidget);


        channelFrameLayout->addLayout(bodyContainer, 1, 0, 1, 1);

        headerContainer = new QHBoxLayout();
        headerContainer->setObjectName(QStringLiteral("headerContainer"));
        channelTitleLabel = new QLabel(ChannelFrame);
        channelTitleLabel->setObjectName(QStringLiteral("channelTitleLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(channelTitleLabel->sizePolicy().hasHeightForWidth());
        channelTitleLabel->setSizePolicy(sizePolicy2);

        headerContainer->addWidget(channelTitleLabel);


        channelFrameLayout->addLayout(headerContainer, 0, 0, 1, 1);


        retranslateUi(ChannelFrame);

        QMetaObject::connectSlotsByName(ChannelFrame);
    } // setupUi

    void retranslateUi(QFrame *ChannelFrame)
    {
        ChannelFrame->setWindowTitle(QApplication::translate("ChannelFrame", "ChannelFrame", 0));
        someButton->setText(QApplication::translate("ChannelFrame", "?", 0));
        chatSubmitButton->setText(QApplication::translate("ChannelFrame", "Chat", 0));
        channelTitleLabel->setText(QApplication::translate("ChannelFrame", "#title", 0));
    } // retranslateUi

};

namespace Ui {
    class ChannelFrame: public Ui_ChannelFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNELFRAME_H
