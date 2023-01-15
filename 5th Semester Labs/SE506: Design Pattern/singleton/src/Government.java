public class Government {

    private static Government instance;
    private String name = "Mr. Albert";

    private Government(){};

    public static Government getInstance(){
        instance = new Government();
        return instance;
    }

    public String getName() {
        return name;
    }

}
