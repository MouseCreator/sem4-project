package vtm.team.models.model;

import jakarta.persistence.*;
import lombok.Data;

@Entity
@Data
@Table(name = "models")
public class Model {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;


    @Override
    public String toString() {
        return "SavedModel{" +
                "id=" + id +
                ", author='" + author + '\'' +
                ", name='" + name + '\'' +
                ", description='" + description + '\'' +
                '}';
    }

    private String author;
    private String name;
    private String description;

}
