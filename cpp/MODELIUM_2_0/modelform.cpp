#include "modelform.h"
#include "qboxlayout.h"
#include "ui_modelform.h"

ModelForm::ModelForm(SavedModel* model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelForm)
{
    ui->setupUi(this);
    this->model = model;

}

ModelForm::~ModelForm()
{
    delete ui;
}
