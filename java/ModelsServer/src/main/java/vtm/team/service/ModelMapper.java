package vtm.team.service;

import org.springframework.stereotype.Component;
import vtm.team.dto.ModelDto;
import vtm.team.model.Model;
@Component
public class ModelMapper {

    public ModelDto parse(Model model) {
        ModelDto modelDto = new ModelDto();
        modelDto.setName(model.getName());
        modelDto.setDescription(model.getDescription());
        modelDto.setFormulas(model.getFormulas());
        modelDto.setGraphMap(model.getGraphMap());
        modelDto.setVarsDescription(model.getVarsDescription());
        return modelDto;
    }
}
