package vtm.team.models.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import vtm.team.models.dto.ModelRequestDto;
import vtm.team.models.dto.ModelResponseDto;
import vtm.team.models.dto.mapper.ModelMapper;
import vtm.team.models.model.Model;
import vtm.team.models.service.ModelService;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@RestController
@RequestMapping("models")
public class ModelController {

    private final ModelService service;
    private final ModelMapper mapper;
    @Autowired
    public ModelController(ModelService service, ModelMapper mapper) {
        this.service = service;
        this.mapper = mapper;
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
    @PostMapping
    public ModelResponseDto create(@RequestBody ModelRequestDto requestDto) {
        Model savedModel = service.save(mapper.toModel(requestDto));
        return mapper.toResponseDto(savedModel);
    }
    @GetMapping
    public List<ModelResponseDto> getAll(@RequestParam Map<String, String> params) {
        return service.findAll(params).stream()
                .map(mapper::toResponseDto).collect(Collectors.toList());
    }
    @DeleteMapping
    public ModelResponseDto delete(@RequestBody ModelRequestDto requestDto) {
        return null;
    }
}
