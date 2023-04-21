#include <iostream>
#include "Graph.h"
#include "formula.h"
#ifndef MODEL_H
#define MODEL_H


class Model
{
public:
    Model(){};

    void add_formula(Formula formula){
        this->formulas.push_back(formula);
    }

    void add_graph(Graph graph){
        this->graphs.push_back(graph);
    }

    std::vector<Formula> formulas;
    std::vector<Graph> graphs;
};

#endif // MODEL_H
