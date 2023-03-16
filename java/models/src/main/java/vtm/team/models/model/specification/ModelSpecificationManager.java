package vtm.team.models.model.specification;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.jpa.domain.Specification;
import org.springframework.stereotype.Component;
import vtm.team.models.model.Model;

import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;
@Component
public class ModelSpecificationManager implements SpecificationManager<Model> {
    private final Map<String, SpecificationProvider<Model>> providerMap;
    @Autowired
    public ModelSpecificationManager(List<SpecificationProvider<Model>> providerList) {
        this.providerMap = providerList.stream()
                .collect(Collectors.toMap(SpecificationProvider::getFilterKey,
                Function.identity()));
    }

    @Override
    public Specification<Model> get(String filterKey, String[] params) {
        if (!providerMap.containsKey(filterKey)) {
            throw new RuntimeException("Key " + filterKey + " is not supported");
        }
        return providerMap.get(filterKey).getSpecification(params);
    }
}
