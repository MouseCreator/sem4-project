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
        this->default_val = default_value;
        this->value = default_value;
    };
    double value;

    std::string get_name(){
        return this->name;
    }
    bool is_constant(){
        return this->is_const;
    }
    double default_value(){
        return this->default_val;
    }
private:
    double default_val;
    bool is_const;
    std::string name;
};

#endif // VARIABLE_H
