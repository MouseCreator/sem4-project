#include "testingform.h"
#include "ui_testingform.h"

TestingForm::TestingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestingForm)
{
    ui->setupUi(this);
}

TestingForm::~TestingForm()
{
    delete ui;
}
