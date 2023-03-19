#include "Expression.h"
#include "variable.h"

#ifndef FORMULA_H
#define FORMULA_H


class Formula
{
public:
    Formula();
    std::string cmopute(){
        expr::Expression expression(this->formula);
        std::vector<std::string> vars = expression.get_vars();
        std::pair<std::string, double> var_map;
    }
private:
    std::string formula;
    std::vector<Variable> vars;
};

#endif // FORMULA_H
