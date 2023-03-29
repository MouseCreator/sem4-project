#include "Expression.h"
#include "variable.h"

#ifndef FORMULA_H
#define FORMULA_H


class Formula
{
private:
    std::string formula;
public:
    std::vector<Variable> vars;
    expr::Expression expression;
    Formula(std::string formula){
        expression = expr::Expression(formula);
    };

    void add_var(Variable var){
        vars.push_back(var);
    }

    std::string compute(){
        std::map<std::string, double> var_map;
        for(int i = 0; i < vars.size(); i++){
            var_map.insert({vars[i].get_name(), vars[i].value});
        }
        return std::to_string(expression.CalculateExpression(var_map));
    }

    /*std::vector<std::string> get_vars(){
        return expression.get_vars();
    }*/
};

#endif // FORMULA_H
