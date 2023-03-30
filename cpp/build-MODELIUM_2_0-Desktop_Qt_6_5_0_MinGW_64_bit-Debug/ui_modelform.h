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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *ModelForm)
    {
        if (ModelForm->objectName().isEmpty())
            ModelForm->setObjectName("ModelForm");
        ModelForm->resize(1263, 671);
        verticalLayoutWidget = new QWidget(ModelForm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 321, 651));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);

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
