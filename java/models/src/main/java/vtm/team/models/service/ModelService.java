package vtm.team.models.service;

import vtm.team.models.model.Model;

import java.util.List;
import java.util.Map;

public interface ModelService {
    Model save(Model model);

    List<Model> findAll(Map<String, String> params);

    List<Model> findAllByNameContainingIgnoreCase(String substring);

}
