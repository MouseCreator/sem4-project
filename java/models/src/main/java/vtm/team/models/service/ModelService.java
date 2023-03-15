package vtm.team.models.service;

import vtm.team.models.model.Model;

import java.util.List;

public interface ModelService {
    Model save(Model model);

    List<Model> findAll();

}
