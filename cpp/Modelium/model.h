#include <iostream>
#include "Expression.h"
#ifndef MODEL_H
#define MODEL_H


class Model
{
public:
    //Enum for storing types of grphs available to the user
    enum Graph{bar, line, pie};
    Model(std::vector<std::string> ,std::map<std::string, std::string> , std::map<Graph, std::vector<std::string>> ,std::string , std::string , std::string );

private:

    ////
    /// Variables stand for forces that are present in the model (like Fg - force of gravity) or certain property of the object in the model (like m - mass)
    ///

    std::map<std::string, std::string> vars_description;
    //Map for storing types of graphs along with the vars tey are supposed to represent (1 graph can show multiple vars)
    std::map<Graph, std::vector<std::string>> graph_map;
    //vector of formulas
    std::vector<std::string> formulas;

    ////
    /// Type stands for type of the simulation like Dynamics or Electromagnetics (might change to enumerator in the future)
    ///
    std::string name, type, description;

};

#endif // MODEL_H
