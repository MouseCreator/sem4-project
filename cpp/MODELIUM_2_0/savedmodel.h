#include "model.h"
#include "feature.h"

#ifndef SAVEDMODEL_H
#define SAVEDMODEL_H

class SavedModel : public Model
{
public:
    SavedModel();
private:
    std::string author;
    std::string name;
    std::string description;
    std::vector<Feature> features;
};

#endif // SAVEDMODEL_H
