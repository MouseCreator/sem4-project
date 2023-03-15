package vtm.team.service;

import org.springframework.stereotype.Component;
import vtm.team.dto.ModelResponseDto;
import vtm.team.model.Model;
@Component
public class ModelMapper {

    public ModelResponseDto parse(Model model) {
        ModelResponseDto modelDto = new ModelResponseDto();
        modelDto.setName(model.getName());
        modelDto.setDescription(model.getDescription());
        modelDto.setFormulas(model.getFormulas());
        modelDto.setGraphMap(model.getGraphMap());
        modelDto.setVarsDescription(model.getVarsDescription());
        return modelDto;
    }
}
