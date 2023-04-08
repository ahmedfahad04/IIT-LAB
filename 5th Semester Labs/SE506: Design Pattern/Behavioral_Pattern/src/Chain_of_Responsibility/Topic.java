package Chain_of_Responsibility;

public class Topic {

    public enum Topics {
        PRINT_TOPIC,
        PAPER_ORIENTATION_TOPIC,
        APPLICATION_TOPIC,
        NO_HELP_TOPIC,
    }

    String value;

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }
}
