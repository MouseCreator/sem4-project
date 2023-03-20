#include <iostream>
#ifndef VARIABLE_H
#define VARIABLE_H


class Variable
{
public:
    Variable();
    Variable(std::string name, bool is_const = false, double default_value = 1.0){
        this->name = name;
        this->is_const = is_const;
        this->default_value = default_value;
        this->value = default_value;
    };
    std::string name;
    bool is_const;
    double value;
    double default_value;
};

#endif // VARIABLE_H
