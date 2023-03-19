package vtm.team.models.dto.mapper;

import org.springframework.stereotype.Component;
import vtm.team.models.dto.ModelRequestDto;
import vtm.team.models.dto.ModelResponseDto;
import vtm.team.models.model.Model;

@Component
public class ModelMapper {
    public ModelResponseDto toResponseDto(Model model) {
        ModelResponseDto responseDto = new ModelResponseDto();
        responseDto.setId(model.getId());
        responseDto.setAuthor(model.getAuthor());
        responseDto.setDescription(model.getDescription());
        responseDto.setName(model.getName());
        return responseDto;
    }
    public Model toModel(ModelRequestDto requestDto) {
        Model model = new Model();
        model.setAuthor(requestDto.getAuthor());
        model.setDescription(requestDto.getDescription());
        model.setName(requestDto.getName());
        return model;
    }
}
