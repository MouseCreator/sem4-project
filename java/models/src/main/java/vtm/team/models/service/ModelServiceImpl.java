package vtm.team.models.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.jpa.domain.Specification;
import org.springframework.stereotype.Service;
import vtm.team.models.model.Model;
import vtm.team.models.model.specification.ModelSpecificationManager;
import vtm.team.models.repository.ModelRepository;

import java.util.List;
import java.util.Map;

@Service
public class ModelServiceImpl implements ModelService {
    private final ModelRepository repository;
    private final ModelSpecificationManager modelSpecificationManager;
    @Autowired
    public ModelServiceImpl(ModelRepository repository, ModelSpecificationManager specificationManager) {
        this.repository = repository;
        this.modelSpecificationManager = specificationManager;
    }

    @Override
    public Model save(Model model) {
        return repository.save(model);
    }

    @Override
    public List<Model> findAll(Map<String, String> params) {
        Specification<Model> specification = null;
        for (Map.Entry<String, String> entry : params.entrySet()) {
            Specification<Model> modelSpecification = modelSpecificationManager.get(entry.getKey(),
                    entry.getValue().split(","));
            specification = specification == null ?
                    Specification.where(modelSpecification) : specification.and(modelSpecification);
        }
        return repository.findAll(specification);

    }
    public List<Model> findAllByNameContainingIgnoreCase(String substring) {
        return repository.findAllByNameContainingIgnoreCase(substring);
    }

    @Override
    public void deleteById(long id) {
        repository.deleteById(id);
    }
}
