package vtm.team.models.model;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import lombok.Data;

@Entity
@Data
public class Formula {
    @Id
    private Long id;
    private String formula;
    private String description;

}
