package vtm.team.models.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import vtm.team.models.model.Model;
import vtm.team.models.service.ModelService;

@RestController
@RequestMapping("models")
public class ModelController {

    private final ModelService service;
    @Autowired
    public ModelController(ModelService service) {
        this.service = service;
    }

    @GetMapping("/inject")
    public void saveModels() {
        Model model = new Model();
        model.setName("Physic");
        model.setDescription("Desc1");
        model.setAuthor("Misha");
        service.save(model);

        Model model2 = new Model();
        model2.setName("Phys");
        model2.setDescription("Description");
        model2.setAuthor("Michael");
        service.save(model2);

        Model model3 = new Model();
        model3.setName("Lenses");
        model3.setDescription("Descriptor");
        model3.setAuthor("Misha");
        service.save(model3);

        service.findAllByNameContainingIgnoreCase("Phy").forEach(System.out::println);
        System.out.println("Reloaded");
    }
}
