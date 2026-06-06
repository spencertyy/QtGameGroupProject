/********************************************************************************
** Form generated from reading UI file 'history.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_history
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_8;
    QLabel *label_10;
    QLineEdit *lineEdit_9;
    QLabel *label_11;
    QLineEdit *lineEdit_10;

    void setupUi(QWidget *history)
    {
        if (history->objectName().isEmpty())
            history->setObjectName("history");
        history->resize(400, 367);
        label = new QLabel(history);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 10, 58, 16));
        lineEdit = new QLineEdit(history);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(40, 50, 281, 21));
        lineEdit_2 = new QLineEdit(history);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(40, 110, 281, 21));
        lineEdit_3 = new QLineEdit(history);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(40, 80, 281, 21));
        lineEdit_4 = new QLineEdit(history);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(40, 140, 281, 21));
        lineEdit_5 = new QLineEdit(history);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(40, 170, 281, 21));
        lineEdit_6 = new QLineEdit(history);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(40, 200, 281, 21));
        lineEdit_7 = new QLineEdit(history);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(40, 230, 281, 21));
        label_2 = new QLabel(history);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 50, 58, 16));
        label_3 = new QLabel(history);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 80, 58, 16));
        label_4 = new QLabel(history);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 110, 58, 16));
        label_5 = new QLabel(history);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 140, 58, 16));
        label_6 = new QLabel(history);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 170, 58, 16));
        label_7 = new QLabel(history);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 200, 58, 16));
        label_8 = new QLabel(history);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 230, 58, 16));
        label_9 = new QLabel(history);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 260, 58, 16));
        lineEdit_8 = new QLineEdit(history);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(40, 260, 281, 21));
        label_10 = new QLabel(history);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 290, 58, 16));
        lineEdit_9 = new QLineEdit(history);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(40, 290, 281, 21));
        label_11 = new QLabel(history);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 320, 58, 16));
        lineEdit_10 = new QLineEdit(history);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(40, 320, 281, 21));

        retranslateUi(history);

        QMetaObject::connectSlotsByName(history);
    } // setupUi

    void retranslateUi(QWidget *history)
    {
        history->setWindowTitle(QCoreApplication::translate("history", "Form", nullptr));
        label->setText(QCoreApplication::translate("history", "History", nullptr));
        label_2->setText(QCoreApplication::translate("history", "1:", nullptr));
        label_3->setText(QCoreApplication::translate("history", "2:", nullptr));
        label_4->setText(QCoreApplication::translate("history", "3:", nullptr));
        label_5->setText(QCoreApplication::translate("history", "4:", nullptr));
        label_6->setText(QCoreApplication::translate("history", "5:", nullptr));
        label_7->setText(QCoreApplication::translate("history", "6:", nullptr));
        label_8->setText(QCoreApplication::translate("history", "7:", nullptr));
        label_9->setText(QCoreApplication::translate("history", "8:", nullptr));
        label_10->setText(QCoreApplication::translate("history", "9:", nullptr));
        label_11->setText(QCoreApplication::translate("history", "10:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class history: public Ui_history {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H
