#include <iostream>
#ifndef VARIABLE_H
#define VARIABLE_H


class Variable
{
public:
    Variable(std::string name, double default_val = 1.0){
        this->name = name;
        is_const = false;
        this->default_val = default_val;
        value = default_val;
    };
    double value;

    std::string get_name(){
        return this->name;
    }

    void set_const(bool is_const){
        this->is_const = is_const;
    }

    void set_def_val(double val){
        this->default_val = val;
    }

    void reset_to_def(){
        value = default_val;
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
