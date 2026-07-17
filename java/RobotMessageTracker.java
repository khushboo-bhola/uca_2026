import java.util.HashMap;

public class RobotMessageTracker {

    HashMap<String, Integer> map = new HashMap<>();

    public void shouldPrintMessage(int timestamp, String message) {
        boolean canPrint = true;
        if (map.containsKey(message)) {
            int lastTime = map.get(message);
            if ((timestamp - lastTime) < 10) {
                canPrint = false;
            } else {
                canPrint = true;
            }
        }
        if (canPrint) {
            map.put(message, timestamp);
            System.out.println(message);
        }
    }
    public static void main(String[] args) {

        RobotMessageTracker logger = new RobotMessageTracker();

        logger.shouldPrintMessage(1, "foo");
        logger.shouldPrintMessage(2, "bar");
        logger.shouldPrintMessage(3, "foo");
        logger.shouldPrintMessage(11, "foo");
    }
}