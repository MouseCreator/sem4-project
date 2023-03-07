/********************************************************************************
** Form generated from reading UI file 'testingform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTINGFORM_H
#define UI_TESTINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestingForm
{
public:
    QLabel *label;

    void setupUi(QWidget *TestingForm)
    {
        if (TestingForm->objectName().isEmpty())
            TestingForm->setObjectName("TestingForm");
        TestingForm->resize(603, 434);
        label = new QLabel(TestingForm);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 20, 161, 20));

        retranslateUi(TestingForm);

        QMetaObject::connectSlotsByName(TestingForm);
    } // setupUi

    void retranslateUi(QWidget *TestingForm)
    {
        TestingForm->setWindowTitle(QCoreApplication::translate("TestingForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("TestingForm", "TESTING FORM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestingForm: public Ui_TestingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTINGFORM_H
