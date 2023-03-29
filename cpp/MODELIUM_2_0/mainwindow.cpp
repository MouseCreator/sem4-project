#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modelform.h"

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
    ModelForm* mf = new ModelForm(nullptr, this);
    mf->show();
}

