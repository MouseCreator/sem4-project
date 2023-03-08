#include "model.h"

Model::Model(std::vector<std::string> formulas,std::map<std::string, std::string> vars, std::map<Graph, std::vector<std::string>> graphs,std::string type, std::string name = "Unnamed Model", std::string description = "No description")
{
    this->name = name;
    this->description = description;
    this->type = type;
    this->vars_description = vars;
    this->graph_map = graphs;
    this->formulas = formulas;
}
