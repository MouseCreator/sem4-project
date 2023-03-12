package vtm.team.model;

import java.util.Map;

public class Model {
    private String name;
    private String type;
    private String description;

    private String[] formulas;

    private Map<Integer, String> graphMap;
    private Map<String, String> varsDescription;

    public Model(String name, String type, String description, String[] formulas,
                 Map<Integer, String> graphMap, Map<String, String> varsDescription) {
        this.name = name;
        this.type = type;
        this.description = description;
        this.formulas = formulas;
        this.graphMap = graphMap;
        this.varsDescription = varsDescription;
    }
}
