package vtm.team.models.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Primary;
import org.springframework.stereotype.Service;
import vtm.team.models.model.Model;

import java.util.List;
import java.util.Map;

@Service
@Primary
public class ModelServiceLogger implements ModelService {
    private final ModelServiceImpl service;
    private final Logger logger;
    @Autowired
    public ModelServiceLogger(ModelServiceImpl service, Logger logger) {
        this.service = service;
        this.logger = logger;
    }

    public Model save(Model model) {
        logger.log("Model " + model.getName() + " by " + model.getAuthor() + " was saved");
        return service.save(model);
    }
    public List<Model> findAll(Map<String, String> params) {
        if (params.isEmpty())
            logger.log("Finding models with no parameters.");
        else {
            StringBuilder builder = new StringBuilder("Finding models with parameters ");
            for (String key : params.keySet()) {
                builder.append("(").append(key).append(" : ").append(params.get(key)).append(") ");
            }
            logger.log(builder.toString());
        }
        return service.findAll(params);
    }

    @Override
    public List<Model> findAllByNameContainingIgnoreCase(String substring) {
        logger.log("Finding all models with " + substring + " in their names");
        return service.findAllByNameContainingIgnoreCase(substring);
    }

    @Override
    public void deleteById(long id) {
        logger.log("Deleting model with id " + id);
        service.deleteById(id);
    }

}
