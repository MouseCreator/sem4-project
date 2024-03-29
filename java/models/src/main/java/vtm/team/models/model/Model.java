package vtm.team.models.model;

import jakarta.persistence.*;
import lombok.Data;

import java.util.List;

@Entity
@Data
@Table(name = "models")
public class Model {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String author;
    private String name;
    private String description;
    @OneToMany
    private List<Formula> formulas;
    @OneToMany
    private List<Variable> variables;

    @OneToMany
    private List<Graph> graphs;


}
