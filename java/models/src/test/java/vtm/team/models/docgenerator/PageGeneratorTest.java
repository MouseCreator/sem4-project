package vtm.team.models.docgenerator;

import org.junit.jupiter.api.Test;
import vtm.team.models.model.Model;

import static org.junit.jupiter.api.Assertions.*;

class PageGeneratorTest {
    @Test
    void generatePage() {
        PageGenerator generator = new PageGenerator();

        Model model = new Model();
        model.setName("Hello");
        model.setDescription("World");

        System.out.println(generator.generatePage(model));
    }
}