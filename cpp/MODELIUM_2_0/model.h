#include <iostream>
#include "Graph.h"
#include "formula.h"
#ifndef MODEL_H
#define MODEL_H


class Model
{
public:
    Model();

protected:
    std::vector<Formula> formulas;
    std::vector<Graph> graphs;
};

#endif // MODEL_H
