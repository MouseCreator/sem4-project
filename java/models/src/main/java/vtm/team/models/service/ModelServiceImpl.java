package vtm.team.models.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import vtm.team.models.model.Model;
import vtm.team.models.repository.ModelRepository;

import java.util.List;
@Service
public class ModelServiceImpl implements ModelService {
    private final ModelRepository repository;
    @Autowired
    public ModelServiceImpl(ModelRepository repository) {
        this.repository = repository;
    }

    @Override
    public Model save(Model model) {
        return repository.save(model);
    }

    @Override
    public List<Model> findAll() {
        return repository.findAll();
    }
    public List<Model> findAllByNameContainingIgnoreCase(String substring) {
        return repository.findAllByNameContainingIgnoreCase(substring);
    }
}
