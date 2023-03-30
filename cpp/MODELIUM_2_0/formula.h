#include "Expression.h"
#include "variable.h"

#ifndef FORMULA_H
#define FORMULA_H


class Formula
{
private:
    std::string name;
    std::string formula;
public:
    std::vector<Variable> vars;
    expr::Expression expression;
    Formula(std::string formula, std::string name = "formula"){
        this->formula = formula;
        expression = expr::Expression(formula);
        std::vector<std::string> input_vars = expression.get_vars();
        for(int i = 0; i < input_vars.size(); i++){
            vars.push_back(Variable(input_vars[i]));
        }
        this->name = name;
    };

    std::string compute(){
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
        return expression.get_vars();
    }
};

#endif // FORMULA_H
