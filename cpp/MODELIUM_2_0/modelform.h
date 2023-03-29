#ifndef MODELFORM_H
#define MODELFORM_H
#include "savedmodel.h"
#include <QDialog>

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

    void set_ui();
};

#endif // MODELFORM_H
