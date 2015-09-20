/********************************************************************************
** Form generated from reading UI file 'ConnectDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDIALOG_H
#define UI_CONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConnectDialog
{
public:
    QLabel *nickLabel;
    QLineEdit *nickLine;
    QLineEdit *networkLine;
    QLineEdit *portLine;
    QLabel *networkLabel;
    QLabel *portLabel;
    QPushButton *connectButton;

    void setupUi(QDialog *ConnectDialog)
    {
        if (ConnectDialog->objectName().isEmpty())
            ConnectDialog->setObjectName(QStringLiteral("ConnectDialog"));
        ConnectDialog->resize(400, 300);
        nickLabel = new QLabel(ConnectDialog);
        nickLabel->setObjectName(QStringLiteral("nickLabel"));
        nickLabel->setGeometry(QRect(30, 50, 47, 13));
        nickLine = new QLineEdit(ConnectDialog);
        nickLine->setObjectName(QStringLiteral("nickLine"));
        nickLine->setGeometry(QRect(110, 50, 113, 20));
        networkLine = new QLineEdit(ConnectDialog);
        networkLine->setObjectName(QStringLiteral("networkLine"));
        networkLine->setGeometry(QRect(110, 80, 113, 20));
        portLine = new QLineEdit(ConnectDialog);
        portLine->setObjectName(QStringLiteral("portLine"));
        portLine->setGeometry(QRect(110, 110, 113, 20));
        networkLabel = new QLabel(ConnectDialog);
        networkLabel->setObjectName(QStringLiteral("networkLabel"));
        networkLabel->setGeometry(QRect(30, 80, 47, 13));
        portLabel = new QLabel(ConnectDialog);
        portLabel->setObjectName(QStringLiteral("portLabel"));
        portLabel->setGeometry(QRect(30, 120, 47, 13));
        connectButton = new QPushButton(ConnectDialog);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(50, 180, 261, 111));

        retranslateUi(ConnectDialog);

        QMetaObject::connectSlotsByName(ConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectDialog)
    {
        ConnectDialog->setWindowTitle(QApplication::translate("ConnectDialog", "Dialog", 0));
        nickLabel->setText(QApplication::translate("ConnectDialog", "Nickname", 0));
        networkLabel->setText(QApplication::translate("ConnectDialog", "Network", 0));
        portLabel->setText(QApplication::translate("ConnectDialog", "Port", 0));
        connectButton->setText(QApplication::translate("ConnectDialog", "C O N N E C T", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectDialog: public Ui_ConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG_H
