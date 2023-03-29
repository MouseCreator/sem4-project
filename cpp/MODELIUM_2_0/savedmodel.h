#include "model.h"
#include "feature.h"

#ifndef SAVEDMODEL_H
#define SAVEDMODEL_H

class SavedModel : public Model
{
public:
    SavedModel(){};

    void set_author(std::string author){
        this->author = author;
    }

    void set_name(std::string name){
        this->name = name;
    }

    void set_description(std::string description){
        this->description = description;
    }

    std::string get_author(){
        return author;
    }

    std::string get_name(){
        return name;
    }

    std::string get_description(){
        return description;
    }
private:
    std::string author;
    std::string name;
    std::string description;
    std::vector<Feature> features;
};

#endif // SAVEDMODEL_H
