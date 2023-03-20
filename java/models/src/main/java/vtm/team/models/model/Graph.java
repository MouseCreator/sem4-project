package vtm.team.models.model;

import jakarta.persistence.*;
import lombok.Data;

@Entity
@Data
@Table(name = "graphs")
public class Graph {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String independentVariable;
    private double independentMin;
    private double independentMax;

    private String functionVariable;
    private double functionMin;
    private double functionMax;
    private double step;

}
