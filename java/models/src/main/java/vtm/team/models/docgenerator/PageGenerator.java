package vtm.team.models.docgenerator;

import vtm.team.models.model.Model;

public class PageGenerator {
    public String generatePage(Model model) {
        String base = """
                <html>
                    <head>
                        <title>%s</title>
                        <styles>

                        </styles>
                    </head>
                    <body>
                        %s
                    </body>
                </html>""";
        return toPage(base, model.getName(), model.getDescription());
    }

    private String toPage(String base, String name, String description) {
        return String.format(base, name, description);
    }
}
