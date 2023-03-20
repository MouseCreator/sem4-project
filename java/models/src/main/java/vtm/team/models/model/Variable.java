package vtm.team.models.model;

import jakarta.persistence.*;
import lombok.Data;
@Entity
@Data
@Table(name = "variables")
public class Variable {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    public enum VariableType {
        CONSTANT, CHANGEABLE, CALCULATED
    }

    private VariableType type;
    private String name;

}
