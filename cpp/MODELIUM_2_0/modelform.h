#ifndef MODELFORM_H
#define MODELFORM_H
#include "savedmodel.h"
#include <QDialog>
#include <QWidget>
#include <QScrollArea>
#include <QLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QMessageBox>

namespace Ui {
class ModelForm;
}

class ModelForm : public QDialog
{
    Q_OBJECT

public:
    explicit ModelForm( SavedModel* model = nullptr, QWidget *parent = nullptr);
    ~ModelForm();

private:
    Ui::ModelForm *ui;
    SavedModel* model;
    std::vector<std::vector<QTextEdit*>> var_inputs;
    std::vector<QLabel*> res_labels;

    void set_ui();
    void compute();
    void compute_single_formula(int id);
    void compute_all();
};

#endif // MODELFORM_H
