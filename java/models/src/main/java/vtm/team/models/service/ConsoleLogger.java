package vtm.team.models.service;

import org.springframework.stereotype.Component;
import vtm.team.models.extra.Dates;

@Component
public class ConsoleLogger implements Logger{
    @Override
    public void log(String message) {
        System.out.println(Dates.timeDate() + message);
    }
}
