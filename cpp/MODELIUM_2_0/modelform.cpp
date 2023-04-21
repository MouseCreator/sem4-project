#include "modelform.h"
#include "ui_modelform.h"
#include <thread>

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
    QWidget* top_bar_widget = new QWidget;
    QHBoxLayout* top_bar_layout = new QHBoxLayout(top_bar_widget);
    QPushButton* stop_button = new QPushButton;
    stop_button->setText(QString::fromUtf8("Stop"));
    QObject::connect(stop_button, &QPushButton::clicked, this, &ModelForm::stop);
    QPushButton* play_button = new QPushButton;
    play_button->setText(QString::fromUtf8("Play"));
    QObject::connect(play_button, &QPushButton::clicked, this, &ModelForm::play);
    QPushButton* prev_button = new QPushButton;
    prev_button->setText(QString::fromUtf8("<-"));
    QObject::connect(prev_button, &QPushButton::clicked, this, &ModelForm::prev_step);
    QPushButton* next_button = new QPushButton;
    next_button->setText(QString::fromUtf8("->"));
    QObject::connect(next_button, &QPushButton::clicked, this, &ModelForm::next_step);
    top_bar_layout->addWidget(stop_button);
    top_bar_layout->addWidget(play_button);
    top_bar_layout->addWidget(prev_button);
    top_bar_layout->addWidget(next_button);
    ui->verticalLayout->addWidget(top_bar_widget);
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
    QWidget* time_set_wg = new QWidget;
    QHBoxLayout* time_set_layout = new QHBoxLayout(time_set_wg);
    QLabel* help_lab = new QLabel("Set time step");
    QTextEdit* time_set_ed = new QTextEdit();
    step_edit = time_set_ed;
    time_set_ed->setPlaceholderText(QString::number(def_time_step));
    time_set_ed->setText(QString::number(def_time_step));
    time_step = def_time_step;
    time_set_ed->setMaximumHeight(30);
    time_set_ed->setMaximumWidth(200);
    time_set_layout->addWidget(help_lab);
    time_set_layout->addWidget(time_set_ed);
    time_set_wg->setMaximumHeight(40);
    ui->verticalLayout->addWidget(main_scroll);
    ui->verticalLayout->addWidget(compute_all_button);
    ui->verticalLayout->addWidget(time_set_wg);
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
    std::vector<std::thread> solvers;
    int thread_num = std::thread::hardware_concurrency();
    for(int i = 0; i < model->formulas.size();){
        for(int j = 0; j < thread_num && i < model->formulas.size(); j++, i++){
            solvers.emplace_back(std::thread(&ModelForm::compute_single_formula, this, i));
        }
        for(int j = 0; j < solvers.size(); j++){
            if(solvers[j].joinable()){
                solvers[j].join();
            }
        }
        solvers.clear();
    }
}

void ModelForm::next_step()
{
    bool ok;
    time_step = step_edit->toPlainText().toDouble(&ok);
    if(!ok){
        QMessageBox::critical(this, "INVALID STEP INPUT", QString::fromUtf8("Invalid value of time step .Enter value of type double"));
        step_edit->clear();
        step_edit->setText(QString::number(def_time_step));
        time_step = def_time_step;
        return;
    }
    for(int i = 0; i < model->formulas.size(); i++){
        int id = model->formulas[i].get_time_var_id();
        if(id != -1){
            model->formulas[i].vars[id].value += time_step;
            var_inputs[i][id]->setText(QString::number(model->formulas[i].vars[id].value));
        }
    }

    compute_all();
}

void ModelForm::prev_step()
{
    bool ok;
    time_step = step_edit->toPlainText().toDouble(&ok);
    if(!ok){
        QMessageBox::critical(this, "INVALID STEP INPUT", QString::fromUtf8("Invalid value of time step .Enter value of type double"));
        step_edit->clear();
        step_edit->setText(QString::number(def_time_step));
        time_step = def_time_step;
        return;
    }
    for(int i = 0; i < model->formulas.size(); i++){
        int id = model->formulas[i].get_time_var_id();
        if(id != -1){
            model->formulas[i].vars[id].value -= time_step;
            if(model->formulas[i].vars[id].value <= 0){
                model->formulas[i].vars[id].value = 0;
            }
            var_inputs[i][id]->setText(QString::number(model->formulas[i].vars[id].value));
        }
    }

    compute_all();
}

void ModelForm::stop()
{

}

void ModelForm::play()
{

}
