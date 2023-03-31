#include "modelform.h"
#include "ui_modelform.h"

ModelForm::ModelForm(SavedModel* model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelForm)
{
    ui->setupUi(this);
    this->model = model;
    set_ui();
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
        QLabel* lab = new QLabel(QString::fromUtf8(model->formulas[i].get_name() + " = " + model->formulas[i].get_formula()));
        main_vlayout->addWidget(lab);
        QWidget* var_wg = new QWidget;
        QScrollArea* var_scroll = new QScrollArea;
        var_scroll->setMaximumHeight(200);
        var_scroll->setMinimumHeight(40);
        QVBoxLayout* var_vlayout = new QVBoxLayout(var_wg);
        var_scroll->setWidget(var_wg);
        var_scroll->setWidgetResizable(true);
        std::vector<QTextEdit*> text_edits;
        for(int j = 0 ; j < model->formulas[i].vars.size(); j++){
            QWidget* wg = new QWidget;
            QLabel* lab = new QLabel(QString::fromUtf8(model->formulas[i].vars[j].get_name()));
            QTextEdit* val_ed = new QTextEdit();
            val_ed->setPlaceholderText(QString::number(model->formulas[i].vars[j].default_value()));
            val_ed->setText(QString::number(model->formulas[i].vars[j].value));
            val_ed->setMaximumHeight(30);
            val_ed->setMaximumWidth(200);
            text_edits.push_back(val_ed);
            QHBoxLayout* hlayout = new QHBoxLayout(wg);
            if(model->formulas[i].vars[j].is_constant()){
                val_ed->setReadOnly(true);
            }
            hlayout->addWidget(lab);
            hlayout->addWidget(val_ed);
            var_vlayout->addWidget(wg);
        }
        var_inputs.push_back(text_edits);
        QWidget* res_wg = new QWidget;
        QLabel* res = new QLabel();
        res->setMaximumWidth(150);
        QPushButton* compute_button = new QPushButton;
        QObject::connect(compute_button, &QPushButton::clicked, this, &ModelForm::compute);
        compute_button->setObjectName(QString::number(i));
        compute_button->setText(QString::fromUtf8(" Compute " + model->formulas[i].get_name()));
        QHBoxLayout* h_lay = new QHBoxLayout(res_wg);
        h_lay->addWidget(compute_button);
        h_lay->addWidget(res);
        res_labels.push_back(res);
        main_vlayout->addWidget(var_scroll);
        main_vlayout->addWidget(res_wg);
    }
    QPushButton* compute_all_button = new QPushButton;
    QObject::connect(compute_all_button, &QPushButton::clicked, this, &ModelForm::compute_all);
    compute_all_button->setText("Compute all formulas");
    compute_all_button->setObjectName("compute_all_button");
    main_vlayout->addWidget(compute_all_button);
    ui->verticalLayout->addWidget(main_scroll);
}

void ModelForm::compute()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    bool is_ok;
    int i = button->objectName().toInt(&is_ok);
    if(!is_ok){
        return;
    }
    compute_single_formula(i);
}

void ModelForm::compute_single_formula(int id)
{
    for(int j = 0; j < var_inputs[id].size(); j++){
        bool ok;
        double new_val = var_inputs[id][j]->toPlainText().toDouble(&ok);
        if(!ok){
            QMessageBox::critical(this, "INVALID VARIABLE INPUT", QString::fromUtf8("Invalid value of variable " + model->formulas[id].vars[j].get_name() + " .Enter value of type double"));
            var_inputs[id][j]->clear();
            model->formulas[id].vars[j].reset_to_def();
        }
        else{
            model->formulas[id].vars[j].value = new_val;
        }
    }
    try {
        res_labels[id]->setText(QString::fromUtf8(model->formulas[id].compute()));
    } catch (std::overflow_error& er) {
        QMessageBox* error_box = new QMessageBox;
        error_box->setText("Overflow error occurred\n");
        error_box->setIcon(QMessageBox::Critical);
        error_box->setWindowTitle("Input Error");
        error_box->exec();
    }

}

void ModelForm::compute_all()
{
    for(int i = 0; i < model->formulas.size(); i++){
        compute_single_formula(i);
    }
}
