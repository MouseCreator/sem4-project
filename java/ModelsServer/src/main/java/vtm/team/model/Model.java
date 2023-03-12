package vtm.team.model;

import java.util.Map;
public class Model {


    private final String name;
    private final String type;
    private final String description;

    private final String[] formulas;

    private final Map<Integer, String> graphMap;
    private final Map<String, String> varsDescription;

    public Model(String name, String type, String description, String[] formulas,
                 Map<Integer, String> graphMap, Map<String, String> varsDescription) {
        this.name = name;
        this.type = type;
        this.description = description;
        this.formulas = formulas;
        this.graphMap = graphMap;
        this.varsDescription = varsDescription;
    }

    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public String getDescription() {
        return description;
    }

    public String[] getFormulas() {
        return formulas;
    }

    public Map<Integer, String> getGraphMap() {
        return graphMap;
    }

    public Map<String, String> getVarsDescription() {
        return varsDescription;
    }
}
