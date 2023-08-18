package practice.singleton;

public class Singleton {
    private static Singleton instance = null;
    private Singleton()
    {

    }

    public static Singleton getInstance(){
        if(instance == null)
            instance = new Singleton();
        return instance;
    }

    public void show(){
//        System.out.println(instance.getClass());
        System.out.println("sup");
    }
}
