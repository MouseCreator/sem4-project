package vtm.team.modelsapp.model.service;

public class HttpConnector {
    private final static String address = "http://26.214.171.81:8089/";
    private final HttpConnector connector;

    public HttpConnector getConnector() {
        return connector;
    }

    public HttpConnector() {
        connector = new HttpConnector();
    }


}
