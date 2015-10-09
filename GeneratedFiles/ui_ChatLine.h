/********************************************************************************
** Form generated from reading UI file 'ChatLine.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLINE_H
#define UI_CHATLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChatLine
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *timeLabel;
    QLabel *userLabel;
    QVBoxLayout *chatMessageLayout;
    QLabel *tempChatMessageLabel;

    void setupUi(QFrame *ChatLine)
    {
        if (ChatLine->objectName().isEmpty())
            ChatLine->setObjectName(QStringLiteral("ChatLine"));
        ChatLine->resize(662, 111);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChatLine->sizePolicy().hasHeightForWidth());
        ChatLine->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Helvetica"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        ChatLine->setFont(font);
        ChatLine->setFrameShape(QFrame::StyledPanel);
        ChatLine->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(ChatLine);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        timeLabel = new QLabel(ChatLine);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(timeLabel->sizePolicy().hasHeightForWidth());
        timeLabel->setSizePolicy(sizePolicy1);
        timeLabel->setMinimumSize(QSize(45, 0));
        timeLabel->setMaximumSize(QSize(45, 16777215));
        timeLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout->addWidget(timeLabel);

        userLabel = new QLabel(ChatLine);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        sizePolicy1.setHeightForWidth(userLabel->sizePolicy().hasHeightForWidth());
        userLabel->setSizePolicy(sizePolicy1);
        userLabel->setMinimumSize(QSize(50, 0));
        userLabel->setMaximumSize(QSize(512, 16777215));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        userLabel->setFont(font1);
        userLabel->setCursor(QCursor(Qt::PointingHandCursor));
        userLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout->addWidget(userLabel);

        chatMessageLayout = new QVBoxLayout();
        chatMessageLayout->setObjectName(QStringLiteral("chatMessageLayout"));
        tempChatMessageLabel = new QLabel(ChatLine);
        tempChatMessageLabel->setObjectName(QStringLiteral("tempChatMessageLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tempChatMessageLabel->sizePolicy().hasHeightForWidth());
        tempChatMessageLabel->setSizePolicy(sizePolicy2);
        tempChatMessageLabel->setWordWrap(true);

        chatMessageLayout->addWidget(tempChatMessageLabel);


        horizontalLayout->addLayout(chatMessageLayout);


        retranslateUi(ChatLine);

        QMetaObject::connectSlotsByName(ChatLine);
    } // setupUi

    void retranslateUi(QFrame *ChatLine)
    {
        ChatLine->setWindowTitle(QApplication::translate("ChatLine", "ChatLine", 0));
        timeLabel->setText(QApplication::translate("ChatLine", "#time", 0));
        userLabel->setText(QApplication::translate("ChatLine", "#user:", 0));
        tempChatMessageLabel->setText(QApplication::translate("ChatLine", "What in Davy Jones' locker did ye just bark at me, ye scurvy bilgerat? I'll have ye know I be the meanest cutthroat on the seven seas, and I've led numerous raids on fishing villages, and raped over 300 wenches. I be trained in hit-and-run pillaging and be the deadliest with a pistol of all the captains on the high seas. Ye be nothing to me but another source o' swag. I'll have yer guts for garters and keel haul ye like never been done before, hear me true.", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatLine: public Ui_ChatLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLINE_H
