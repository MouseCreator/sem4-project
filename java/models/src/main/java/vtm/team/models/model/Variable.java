package vtm.team.models.model;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import lombok.Data;
@Entity
@Data
public class Variable {
    @Id
    private Long id;

    public enum VariableType {
        CONSTANT, CHANGEABLE, CALCULATED
    }

    private VariableType type;
    private String name;

}
