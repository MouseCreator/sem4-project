package vtm.team.models.model.specification;

import org.springframework.data.jpa.domain.Specification;

public interface SpecificationManager<M> {


    Specification<M> get(String filterKey, String[] params);
}
