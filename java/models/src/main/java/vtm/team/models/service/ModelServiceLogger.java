package vtm.team.models.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import vtm.team.models.model.Model;
@Component
public class ModelServiceLogger {
    private final ModelServiceImpl service;
    private final Logger logger;
    @Autowired
    public ModelServiceLogger(ModelServiceImpl service, Logger logger) {
        this.service = service;
        this.logger = logger;
    }

    public void save(Model model) {
        service.save(model);
        logger.log("Model " + model.getName() + " by " + model.getAuthor() + " was saved");
    }

}
