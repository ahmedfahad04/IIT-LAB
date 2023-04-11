package Factory_Method;

public class ChickenBurgerRestaurant extends Restaurant{

    // FACTORY METHOD
    @Override
    public Burger createBurger() {
        return new ChickenBurger();
    }
}
