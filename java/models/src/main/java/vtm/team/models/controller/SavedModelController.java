package vtm.team.models.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import vtm.team.models.model.Model;

@RestController
@RequestMapping("models")
public class SavedModelController {
    @GetMapping("/inject")
    public void saveModels() {
        Model model = new Model();
        model.setName("Physic");
        model.setDescription("Desc1");
        model.setAuthor("Misha");
    }
}
