package vtm.team.modelsapp.model.main.documentation;

import java.lang.reflect.Field;

public class DocumentationManager {

    public String getDocumentation(Class<?> interfaceClass) {
        Field[] declaredFields = interfaceClass.getDeclaredFields();

        for (Field field : declaredFields) {
            if (field.isAnnotationPresent(DocumentationPart.class)) {
                if (field.getDeclaringClass().)
            }
        }
    }
}
