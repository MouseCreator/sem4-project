#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modelform.h"
#include "savedmodel.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    SavedModel* md = new SavedModel;
    md->add_formula(Formula("x/(1-1)", "formula 1"));
    md->add_formula(Formula("2*m/g", "formula 2"));
    md->add_formula(Formula("v*t", "formula 3"));
    md->add_formula(Formula("x*y*z*a*b*c*d*e*f*g*h*j*k*l*m*u*i", "formula 4"));
    for(int i = 0; i < md->formulas.size(); i++){
        for(int j = 0; j < md->formulas[i].vars.size(); j++){
            md->formulas[i].vars[j].value = (static_cast<double>(rand()%10+1))/100.0;
            md->formulas[i].vars[j].set_const(rand()%2);
        }
    }
    ModelForm* mf = new ModelForm(md, this);
    mf->show();
}

