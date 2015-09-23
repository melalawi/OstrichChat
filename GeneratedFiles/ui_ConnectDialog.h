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
    QLabel *channelLabel;
    QLineEdit *channelLine;
    QPushButton *connectButton;

    void setupUi(QDialog *ConnectDialog)
    {
        if (ConnectDialog->objectName().isEmpty())
            ConnectDialog->setObjectName(QStringLiteral("ConnectDialog"));
        ConnectDialog->resize(267, 88);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConnectDialog->sizePolicy().hasHeightForWidth());
        ConnectDialog->setSizePolicy(sizePolicy);
        channelLabel = new QLabel(ConnectDialog);
        channelLabel->setObjectName(QStringLiteral("channelLabel"));
        channelLabel->setGeometry(QRect(30, 20, 81, 16));
        channelLine = new QLineEdit(ConnectDialog);
        channelLine->setObjectName(QStringLiteral("channelLine"));
        channelLine->setGeometry(QRect(110, 20, 131, 21));
        connectButton = new QPushButton(ConnectDialog);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setEnabled(false);
        connectButton->setGeometry(QRect(90, 50, 91, 31));

        retranslateUi(ConnectDialog);

        QMetaObject::connectSlotsByName(ConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectDialog)
    {
        ConnectDialog->setWindowTitle(QApplication::translate("ConnectDialog", "Connect To Channel!", 0));
        channelLabel->setText(QApplication::translate("ConnectDialog", "Channel Name:", 0));
        connectButton->setText(QApplication::translate("ConnectDialog", "C O N N E C T", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectDialog: public Ui_ConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG_H
