package vtm.team.models.model;

import jakarta.persistence.*;

@Entity
@Table(name = "savedModels")
public class SavedModel {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String author;
    private String name;
    private String description;

}
