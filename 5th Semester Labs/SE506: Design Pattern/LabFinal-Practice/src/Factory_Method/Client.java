package Factory_Method;

public class Client {

    public static void main(String[] args) {
        Restaurant beefRestaurant = new BeefBurgerRestaurant();
        beefRestaurant.orderBurger();
    }


}
