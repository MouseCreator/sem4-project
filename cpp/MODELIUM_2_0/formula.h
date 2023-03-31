#include "Expression.h"
#include "variable.h"
#include <QMessageBox>
#ifndef FORMULA_H
#define FORMULA_H


class Formula
{
private:
    std::string name;
    std::string formula;
    bool is_broken = false;
public:
    std::vector<Variable> vars;
    expr::Expression expression;
    Formula(std::string formula, std::string name = "formula"){
        this->formula = formula;
        this->name = name;
        try {
            expression = expr::Expression(formula);
            std::vector<std::string> input_vars = expression.get_vars();
            for(int i = 0; i < input_vars.size(); i++){
                vars.push_back(Variable(input_vars[i]));
            }
        }
        catch (std::runtime_error& e) {
            QMessageBox* error_box = new QMessageBox;
            error_box->setText("Invalid input (missing or extra brackets or invalid symbols\n");
            error_box->setIcon(QMessageBox::Critical);
            error_box->setWindowTitle("Input Error");
            error_box->exec();
            is_broken = true;
        }
    };

    std::string compute(){
        if(is_broken){
            QMessageBox* error_box = new QMessageBox;
            error_box->setText("This formula is broken, define it correctly to compute\n");
            error_box->setIcon(QMessageBox::Critical);
            error_box->setWindowTitle("Input Error");
            error_box->exec();
            return "0";
        }
        std::map<std::string, double> var_map;
        for(int i = 0; i < vars.size(); i++){
            var_map.insert({vars[i].get_name(), vars[i].value});
        }
        return std::to_string(expression.CalculateExpression(var_map));
    }

    std::string get_name(){
        return name;
    }

    std::string get_formula(){
        return this->formula;
    }

    std::vector<std::string> get_vars(){
        if(is_broken){
            QMessageBox* error_box = new QMessageBox;
            error_box->setText("This formula is broken, define it correctly to compute\n");
            error_box->setIcon(QMessageBox::Critical);
            error_box->setWindowTitle("Input Error");
            error_box->exec();
            return std::vector<std::string>();
        }
        return expression.get_vars();
    }
};

#endif // FORMULA_H
