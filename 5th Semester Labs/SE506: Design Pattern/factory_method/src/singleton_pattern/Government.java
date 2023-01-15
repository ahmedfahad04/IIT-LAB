package singleton_pattern;

public class Government {
    public static Government instance;

    private Government() {};

    public static Government getInstance() {
        instance = new Government();
        return instance;
    }
}
