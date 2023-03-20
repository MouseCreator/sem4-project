/********************************************************************************
** Form generated from reading UI file 'modelform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELFORM_H
#define UI_MODELFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelForm
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *ModelForm)
    {
        if (ModelForm->objectName().isEmpty())
            ModelForm->setObjectName("ModelForm");
        ModelForm->resize(606, 564);
        scrollArea = new QScrollArea(ModelForm);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 20, 221, 81));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 219, 79));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(ModelForm);

        QMetaObject::connectSlotsByName(ModelForm);
    } // setupUi

    void retranslateUi(QDialog *ModelForm)
    {
        ModelForm->setWindowTitle(QCoreApplication::translate("ModelForm", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelForm: public Ui_ModelForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELFORM_H
