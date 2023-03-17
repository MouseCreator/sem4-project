package vtm.team.modelsapp.model.main;

import java.util.Set;

import vtm.team.modelsapp.model.main.documentation.DocumentationPart;
import vtm.team.modelsapp.model.main.documentation.DocumentationProvider;

public class Model implements DocumentationProvider {
    private String name;
    private String description;
    @DocumentationPart(name = "Variables")
    private Set<Variable> variables;

    @DocumentationPart(name = "Contributors")
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

    @Override
    public String toDocumentation() {
        return null;
    }
}
