/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *kord2;
    QLineEdit *kord;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *kord3;
    QLineEdit *kord4;
    QLineEdit *kord5;

    void setupUi(QDialog *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QString::fromUtf8("SecondWindow"));
        SecondWindow->resize(400, 188);
        gridLayout = new QGridLayout(SecondWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(SecondWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        kord2 = new QLineEdit(SecondWindow);
        kord2->setObjectName(QString::fromUtf8("kord2"));

        gridLayout->addWidget(kord2, 3, 1, 1, 1);

        kord = new QLineEdit(SecondWindow);
        kord->setObjectName(QString::fromUtf8("kord"));
        kord->setMaximumSize(QSize(134, 20));

        gridLayout->addWidget(kord, 2, 1, 1, 1);

        label = new QLabel(SecondWindow);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        label_4 = new QLabel(SecondWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 1);

        label_5 = new QLabel(SecondWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        label_3 = new QLabel(SecondWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        kord3 = new QLineEdit(SecondWindow);
        kord3->setObjectName(QString::fromUtf8("kord3"));

        gridLayout->addWidget(kord3, 4, 1, 1, 1);

        kord4 = new QLineEdit(SecondWindow);
        kord4->setObjectName(QString::fromUtf8("kord4"));

        gridLayout->addWidget(kord4, 5, 1, 1, 1);

        kord5 = new QLineEdit(SecondWindow);
        kord5->setObjectName(QString::fromUtf8("kord5"));

        gridLayout->addWidget(kord5, 6, 1, 1, 1);


        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QDialog *SecondWindow)
    {
        SecondWindow->setWindowTitle(QCoreApplication::translate("SecondWindow", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("SecondWindow", "\320\232\320\276\320\276\321\200-\321\202\321\213 \320\275\320\260\321\207\320\260\320\273\320\260 1 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
        label->setText(QCoreApplication::translate("SecondWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\202\320\276\321\207\320\272\320\270:", nullptr));
        label_4->setText(QCoreApplication::translate("SecondWindow", "\320\232\320\276\320\276\321\200-\321\202\321\213 \320\275\320\260\321\207\320\260\320\273\320\260 2 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("SecondWindow", "\320\232\320\276\320\276\321\200-\321\202\321\213 \320\272\320\276\320\275\321\206\320\260 2 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("SecondWindow", "\320\232\320\276\320\276\321\200-\321\202\321\213 \320\272\320\276\320\275\321\206\320\260 1 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
