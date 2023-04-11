package Abstract_Factory;

public class ChickenBurgerRestaurant extends Restaurant {

    // FACTORY METHOD
    @Override
    public Burger createBurger() {
        return new ChickenBurger();
    }

    @Override
    public Packer packBurger() {
        return new PlatinumBurgerPack();
    }
}
