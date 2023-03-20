package vtm.team.models.model;

import jakarta.persistence.*;
import lombok.Data;

@Entity
@Data
@Table(name = "formulas")
public class Formula {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String formula;
    private String description;
}
