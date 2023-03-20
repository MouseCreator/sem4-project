package vtm.team.models.extra;

import java.time.LocalDateTime;

public abstract class Dates {
    public static String timeDate() {
        return "[" + LocalDateTime.now() + "] ";
    }
}
