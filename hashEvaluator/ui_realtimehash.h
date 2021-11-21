/********************************************************************************
** Form generated from reading UI file 'realtimehash.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REALTIMEHASH_H
#define UI_REALTIMEHASH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RealTimeHash
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTextBrowser *output_field;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QTextEdit *input_field;
    QRadioButton *sha_hash_radio_button;
    QRadioButton *md5_hash_radio_button;
    QRadioButton *keccak_hash_radio_button;
    QPushButton *clear_button;
    QPushButton *exit_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RealTimeHash)
    {
        if (RealTimeHash->objectName().isEmpty())
            RealTimeHash->setObjectName(QString::fromUtf8("RealTimeHash"));
        RealTimeHash->resize(938, 388);
        RealTimeHash->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);\n"
"alternate-background-color: rgb(136, 138, 133);\n"
"border-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(RealTimeHash);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        output_field = new QTextBrowser(centralwidget);
        output_field->setObjectName(QString::fromUtf8("output_field"));
        output_field->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(output_field);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        input_field = new QTextEdit(centralwidget);
        input_field->setObjectName(QString::fromUtf8("input_field"));
        input_field->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(input_field);

        sha_hash_radio_button = new QRadioButton(centralwidget);
        sha_hash_radio_button->setObjectName(QString::fromUtf8("sha_hash_radio_button"));
        sha_hash_radio_button->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));

        verticalLayout_2->addWidget(sha_hash_radio_button);

        md5_hash_radio_button = new QRadioButton(centralwidget);
        md5_hash_radio_button->setObjectName(QString::fromUtf8("md5_hash_radio_button"));
        md5_hash_radio_button->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(md5_hash_radio_button);

        keccak_hash_radio_button = new QRadioButton(centralwidget);
        keccak_hash_radio_button->setObjectName(QString::fromUtf8("keccak_hash_radio_button"));
        keccak_hash_radio_button->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(keccak_hash_radio_button);

        clear_button = new QPushButton(centralwidget);
        clear_button->setObjectName(QString::fromUtf8("clear_button"));
        clear_button->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));

        verticalLayout_2->addWidget(clear_button);

        exit_button = new QPushButton(centralwidget);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));
        exit_button->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));

        verticalLayout_2->addWidget(exit_button);


        verticalLayout->addLayout(verticalLayout_2);

        RealTimeHash->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RealTimeHash);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 938, 21));
        RealTimeHash->setMenuBar(menubar);
        statusbar = new QStatusBar(RealTimeHash);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RealTimeHash->setStatusBar(statusbar);

        retranslateUi(RealTimeHash);

        QMetaObject::connectSlotsByName(RealTimeHash);
    } // setupUi

    void retranslateUi(QMainWindow *RealTimeHash)
    {
        RealTimeHash->setWindowTitle(QCoreApplication::translate("RealTimeHash", "RealTimeHash", nullptr));
        label->setText(QCoreApplication::translate("RealTimeHash", "hashed output", nullptr));
        label_2->setText(QCoreApplication::translate("RealTimeHash", "Input field", nullptr));
        sha_hash_radio_button->setText(QCoreApplication::translate("RealTimeHash", "Sha512", nullptr));
        md5_hash_radio_button->setText(QCoreApplication::translate("RealTimeHash", "MD5", nullptr));
        keccak_hash_radio_button->setText(QCoreApplication::translate("RealTimeHash", "Keccak_512", nullptr));
        clear_button->setText(QCoreApplication::translate("RealTimeHash", "Clear", nullptr));
        exit_button->setText(QCoreApplication::translate("RealTimeHash", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RealTimeHash: public Ui_RealTimeHash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REALTIMEHASH_H
