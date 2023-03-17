package vtm.team.modelsapp.model.main;

import java.util.Set;

public class Model {
    private String name;
    private String description;
    private Set<Variable> variables;
    private Set<User> contributors;

    public Model (String name, String description, Set<Variable> variables, Set<User> contributors) {
        this.name = name;
        this.description = description;
        this.variables = variables;
        this.contributors = contributors;
    }
    public Model clone() {
        return new Model(name, description, variables, contributors);
    }
}
