package vtm.team.models.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import vtm.team.models.model.Model;

public interface ModelRepository extends JpaRepository<Model, Long> {
}
