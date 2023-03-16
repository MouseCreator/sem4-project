package vtm.team.models.repository;

import org.springframework.data.jpa.domain.Specification;
import org.springframework.data.jpa.repository.JpaRepository;
import vtm.team.models.model.Model;

import java.util.List;

public interface ModelRepository extends JpaRepository<Model, Long> {
    List<Model> findAllByNameContainingIgnoreCase(String substring);

    List<Model> findAll(Specification<Model> specification);
}
