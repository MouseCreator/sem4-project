package vtm.team.modelsapp.model.main;

import vtm.team.modelsapp.model.main.documentation.DocumentationProvider;

public class NumericVariable implements Variable, DocumentationProvider {
    private String name;
    private String description;
    private String formula;

    @Override
    public String toDocumentation() {
        return null;
    }
}
