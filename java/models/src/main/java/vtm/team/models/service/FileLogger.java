package vtm.team.models.service;

import org.springframework.context.annotation.Primary;
import org.springframework.stereotype.Component;
import vtm.team.models.extra.Dates;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

@Component
@Primary
public class FileLogger implements Logger {
    @Override
    public void log(String message) {
        try {
            String filename = "src/main/resources/files/output.txt";
            BufferedWriter writer = new BufferedWriter(new FileWriter(filename, true));
            writer.write(Dates.timeDate() + message);
            writer.newLine();
            writer.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }


}
