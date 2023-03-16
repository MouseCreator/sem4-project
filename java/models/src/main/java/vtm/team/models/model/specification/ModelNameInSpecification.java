package vtm.team.models.model.specification;

import jakarta.persistence.criteria.CriteriaBuilder;
import org.springframework.data.jpa.domain.Specification;
import org.springframework.stereotype.Component;
import vtm.team.models.model.Model;
@Component
public class ModelNameInSpecification implements SpecificationProvider<Model> {

    private static final String FILTER_KEY_URL = "nameIn";
    private static final String FIELD_NAME = "name";
    @Override
    public Specification<Model> getSpecification(String[] names) {
        return ((root, query, criteriaBuilder) -> {
            CriteriaBuilder.In<String> predicate = criteriaBuilder.in(root.get(FIELD_NAME));
            for (String v : names) {
                predicate.value(v);
            }
            return criteriaBuilder.and(predicate, predicate);
        });
    }

    @Override
    public String getFilterKey() {
        return FILTER_KEY_URL;
    }
}
