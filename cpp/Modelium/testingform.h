#ifndef TESTINGFORM_H
#define TESTINGFORM_H

#include <QDialog>

namespace Ui {
class TestingForm;
}

class TestingForm : public QDialog
{
    Q_OBJECT

public:
    explicit TestingForm(QWidget *parent = nullptr);
    ~TestingForm();

private:
    Ui::TestingForm *ui;
};

#endif // TESTINGFORM_H
