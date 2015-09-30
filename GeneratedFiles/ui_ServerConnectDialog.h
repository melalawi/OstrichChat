/********************************************************************************
** Form generated from reading UI file 'ServerConnectDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERCONNECTDIALOG_H
#define UI_SERVERCONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerConnectDialog
{
public:
    QWidget *gridLayoutWidget;
    QVBoxLayout *dialogLayout;
    QLabel *titleLabel;
    QLabel *methodOneLabel;
    QPushButton *twitchLoginButton;
    QLabel *methodTwoLabel;
    QVBoxLayout *manualCredentialsLayout;
    QLineEdit *usernameLine;
    QLineEdit *oAuthTokenLine;
    QPushButton *manualLoginButton;

    void setupUi(QDialog *ServerConnectDialog)
    {
        if (ServerConnectDialog->objectName().isEmpty())
            ServerConnectDialog->setObjectName(QStringLiteral("ServerConnectDialog"));
        ServerConnectDialog->resize(252, 203);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ServerConnectDialog->sizePolicy().hasHeightForWidth());
        ServerConnectDialog->setSizePolicy(sizePolicy);
        gridLayoutWidget = new QWidget(ServerConnectDialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 251, 201));
        dialogLayout = new QVBoxLayout(gridLayoutWidget);
        dialogLayout->setSpacing(10);
        dialogLayout->setObjectName(QStringLiteral("dialogLayout"));
        dialogLayout->setContentsMargins(5, 5, 5, 5);
        titleLabel = new QLabel(gridLayoutWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setTextFormat(Qt::AutoText);

        dialogLayout->addWidget(titleLabel);

        methodOneLabel = new QLabel(gridLayoutWidget);
        methodOneLabel->setObjectName(QStringLiteral("methodOneLabel"));
        methodOneLabel->setTextFormat(Qt::AutoText);

        dialogLayout->addWidget(methodOneLabel);

        twitchLoginButton = new QPushButton(gridLayoutWidget);
        twitchLoginButton->setObjectName(QStringLiteral("twitchLoginButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(twitchLoginButton->sizePolicy().hasHeightForWidth());
        twitchLoginButton->setSizePolicy(sizePolicy1);
        twitchLoginButton->setMaximumSize(QSize(170, 32));
        twitchLoginButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/OstrichChat/twitchConnectButton"), QSize(), QIcon::Normal, QIcon::Off);
        twitchLoginButton->setIcon(icon);
        twitchLoginButton->setIconSize(QSize(170, 32));

        dialogLayout->addWidget(twitchLoginButton, 0, Qt::AlignHCenter);

        methodTwoLabel = new QLabel(gridLayoutWidget);
        methodTwoLabel->setObjectName(QStringLiteral("methodTwoLabel"));
        methodTwoLabel->setTextFormat(Qt::AutoText);

        dialogLayout->addWidget(methodTwoLabel);

        manualCredentialsLayout = new QVBoxLayout();
        manualCredentialsLayout->setObjectName(QStringLiteral("manualCredentialsLayout"));
        manualCredentialsLayout->setSizeConstraint(QLayout::SetFixedSize);
        manualCredentialsLayout->setContentsMargins(50, -1, 50, 15);
        usernameLine = new QLineEdit(gridLayoutWidget);
        usernameLine->setObjectName(QStringLiteral("usernameLine"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(usernameLine->sizePolicy().hasHeightForWidth());
        usernameLine->setSizePolicy(sizePolicy2);
        usernameLine->setMinimumSize(QSize(0, 20));

        manualCredentialsLayout->addWidget(usernameLine);

        oAuthTokenLine = new QLineEdit(gridLayoutWidget);
        oAuthTokenLine->setObjectName(QStringLiteral("oAuthTokenLine"));
        oAuthTokenLine->setMinimumSize(QSize(0, 20));

        manualCredentialsLayout->addWidget(oAuthTokenLine);

        manualLoginButton = new QPushButton(gridLayoutWidget);
        manualLoginButton->setObjectName(QStringLiteral("manualLoginButton"));
        manualLoginButton->setEnabled(false);
        manualLoginButton->setMinimumSize(QSize(0, 23));

        manualCredentialsLayout->addWidget(manualLoginButton, 0, Qt::AlignHCenter);


        dialogLayout->addLayout(manualCredentialsLayout);


        retranslateUi(ServerConnectDialog);

        QMetaObject::connectSlotsByName(ServerConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *ServerConnectDialog)
    {
        ServerConnectDialog->setWindowTitle(QApplication::translate("ServerConnectDialog", "Login to Twitch.tv", 0));
        titleLabel->setText(QApplication::translate("ServerConnectDialog", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; text-decoration: underline;\">Two Ways to Login:</span></p></body></html>", 0));
        methodOneLabel->setText(QApplication::translate("ServerConnectDialog", "<html><head/><body><p><span style=\" font-size:10pt;\">1) Automatically via Twitch.tv:</span></p></body></html>", 0));
        twitchLoginButton->setText(QString());
        methodTwoLabel->setText(QApplication::translate("ServerConnectDialog", "<html><head/><body><p><span style=\" font-size:9pt;\">2) Manually by Entering These Credentials:</span></p></body></html>", 0));
        usernameLine->setPlaceholderText(QApplication::translate("ServerConnectDialog", "Twitch.tv Username", 0));
        oAuthTokenLine->setPlaceholderText(QApplication::translate("ServerConnectDialog", "Twitch OAuth Token", 0));
        manualLoginButton->setText(QApplication::translate("ServerConnectDialog", "Login", 0));
    } // retranslateUi

};

namespace Ui {
    class ServerConnectDialog: public Ui_ServerConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERCONNECTDIALOG_H
