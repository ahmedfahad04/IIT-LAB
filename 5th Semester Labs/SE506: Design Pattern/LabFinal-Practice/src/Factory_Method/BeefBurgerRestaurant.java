package Factory_Method;

public class BeefBurgerRestaurant extends Restaurant {

    // FACTORY METHOD
    @Override
    public Burger createBurger() {
        return new BeefBurger();
    }
}
