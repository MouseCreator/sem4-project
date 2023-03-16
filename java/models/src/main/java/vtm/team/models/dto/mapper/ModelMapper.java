package vtm.team.models.dto.mapper;

import org.springframework.stereotype.Component;
import vtm.team.models.dto.ModelRequestDto;
import vtm.team.models.dto.ModelResponseDto;
import vtm.team.models.model.Model;

@Component
public class ModelMapper {
    public ModelResponseDto toResponseDto(Model model) {
        return null;
    }
    public Model toModel(ModelRequestDto model) {
        return null;
    }
}
