#include "modelform.h"
#include <QWidget>
#include <QScrollArea>
#include <QLayout>
#include <QLabel>
#include <QTextEdit>
#include "ui_modelform.h"

ModelForm::ModelForm(SavedModel* model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelForm)
{
    ui->setupUi(this);
    this->model = model;
    set_ui();
    /*Formula f1("x+y+z");
    std::vector<std::string> vars = f1.get_vars();
    for(int i = 0; i < vars.size(); i++){
        Variable var(vars[i]);
        var.set_def_val(10.0);
        f1.add_var(var);
    }
    Formula f2("2*4+31*ad+ad");
    vars = f2.get_vars();
    for(int i = 0; i < vars.size(); i++){
        Variable var(vars[i]);
        var.set_def_val(10.0);
        f2.add_var(var);
    }
    QWidget* central = new QWidget();
    QScrollArea* scroll = new QScrollArea();
    QVBoxLayout* vlayout = new QVBoxLayout(central);
    scroll->setWidget(central);
    scroll->setWidgetResizable(true);
    /*for(int i = 0; i < 60; i++){
        QLabel* test_label = new QLabel(QString("TEST WORD"));
        vlayout->addWidget(test_label);
    }
    QLabel* label1 = new QLabel(QString("Formula 1"));
    vlayout->addWidget(label1);
    QWidget* var_widget1 = new QWidget;
    QScrollArea* var_scroll1 = new QScrollArea();
    QVBoxLayout* var_lay1 = new QVBoxLayout(var_widget1);
    var_scroll1->setWidget(var_widget1);
    var_scroll1->setWidgetResizable(true);
    for(int i = 0; i < f1.vars.size(); i++){
        QWidget* wg = new QWidget();
        QHBoxLayout* hor_lay = new QHBoxLayout(wg);
        QLabel* lab1 = new QLabel(QString::fromUtf8(f1.vars[i].get_name()));
        QLabel* lab2 = new QLabel(QString::fromUtf8(std::to_string(f1.vars[i].value)));
        hor_lay->addWidget(lab1);
        hor_lay->addWidget(lab2);
        var_lay1->addWidget(wg);
    }
    vlayout->addWidget(var_scroll1);
    QLabel* label2 = new QLabel(QString("Formula 2"));
    vlayout->addWidget(label2);
    QWidget* var_widget2 = new QWidget;
    QScrollArea* var_scroll2 = new QScrollArea();
    QVBoxLayout* var_lay2 = new QVBoxLayout(var_widget2);
    var_scroll2->setWidget(var_widget2);
    var_scroll2->setWidgetResizable(true);
    for(int i = 0; i < f2.vars.size(); i++){
        QWidget* wg = new QWidget();
        QHBoxLayout* hor_lay = new QHBoxLayout(wg);
        QLabel* lab1 = new QLabel(QString::fromUtf8(f2.vars[i].get_name()));
        QLabel* lab2 = new QLabel(QString::fromUtf8(std::to_string(f2.vars[i].value)));
        hor_lay->addWidget(lab1);
        hor_lay->addWidget(lab2);
        var_lay2->addWidget(wg);
    }
    vlayout->addWidget(var_scroll2);

    QVBoxLayout* main_layout = ui->verticalLayout;
    main_layout->addWidget(scroll);*/
}



ModelForm::~ModelForm()
{
    delete ui;
}

void ModelForm::set_ui()
{
    QWidget* main_wg = new QWidget;
    QScrollArea* main_scroll = new QScrollArea;
    QVBoxLayout* main_vlayout = new QVBoxLayout(main_wg);
    main_scroll->setWidget(main_wg);
    main_scroll->setWidgetResizable(true);
    for(int i = 0; i < model->formulas.size(); i++){
        QLabel* lab = new QLabel(QString::fromUtf8(model->formulas[i].get_name()));
        main_vlayout->addWidget(lab);
        QWidget* var_wg = new QWidget;
        QScrollArea* var_scroll = new QScrollArea;
        var_scroll->setMaximumHeight(200);
        var_scroll->setMinimumHeight(40);
        QVBoxLayout* var_vlayout = new QVBoxLayout(var_wg);
        var_scroll->setWidget(var_wg);
        var_scroll->setWidgetResizable(true);
        for(int j = 0 ; j < model->formulas[i].vars.size(); j++){
            QWidget* wg = new QWidget;
            QLabel* lab = new QLabel(QString::fromUtf8(model->formulas[i].vars[j].get_name()));
            QTextEdit* val_ed = new QTextEdit();
            val_ed->setPlaceholderText(QString::number(model->formulas[i].vars[j].value));
            val_ed->setMaximumHeight(30);
            val_ed->setMaximumWidth(200);
            QHBoxLayout* hlayout = new QHBoxLayout(wg);
            if(model->formulas[i].vars[j].is_constant()){
                val_ed->setReadOnly(true);
            }
            hlayout->addWidget(lab);
            hlayout->addWidget(val_ed);
            var_vlayout->addWidget(wg);
        }
        main_vlayout->addWidget(var_scroll);
    }
    ui->verticalLayout->addWidget(main_scroll);
}
