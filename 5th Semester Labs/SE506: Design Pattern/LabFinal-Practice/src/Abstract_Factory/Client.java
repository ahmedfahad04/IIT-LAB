package Abstract_Factory;

public class Client {

    public static void main(String[] args) {
        Restaurant beefRestaurant = new BeefBurgerRestaurant();
        Burger burger =  beefRestaurant.createBurger();
        Packer pack = beefRestaurant.packBurger();
    }


}
