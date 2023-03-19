package vtm.team.dto;

import java.util.Map;

public class ModelResponseDto {

    private int id;
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String[] getFormulas() {
        return formulas;
    }

    public void setFormulas(String[] formulas) {
        this.formulas = formulas;
    }

    public Map<Integer, String> getGraphMap() {
        return graphMap;
    }

    public void setGraphMap(Map<Integer, String> graphMap) {
        this.graphMap = graphMap;
    }

    public Map<String, String> getVarsDescription() {
        return varsDescription;
    }

    public void setVarsDescription(Map<String, String> varsDescription) {
        this.varsDescription = varsDescription;
    }

    private String name;
    private String type;
    private String description;

    private String[] formulas;

    private Map<Integer, String> graphMap;
    private Map<String, String> varsDescription;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
