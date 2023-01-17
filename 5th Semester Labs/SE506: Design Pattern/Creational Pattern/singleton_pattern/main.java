package singleton_pattern;

public class main {
    public static void main(String[] args) {
        Government government = Government.getInstance();
        Government g2 = Government.getInstance();
        System.out.println(government);
        System.out.println(g2);
    }
}
