package vtm.team.models.service;

import org.springframework.stereotype.Component;

@Component
public interface Logger {
    void log(String message);
}
