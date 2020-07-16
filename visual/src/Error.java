import static java.lang.System.exit;

public interface Error {
    default void error(String message) {
        System.out.println(message);
        exit(0);
    }

    default void error(String message, Exception e) {
        System.out.println(message);
        e.printStackTrace();
        exit(0);
    }
}
