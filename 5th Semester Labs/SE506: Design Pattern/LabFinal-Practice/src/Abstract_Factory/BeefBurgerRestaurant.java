package Abstract_Factory;

public class BeefBurgerRestaurant extends Restaurant {

    // FACTORY METHOD
    @Override
    public Burger createBurger() {
        System.out.println("Beef Burger Creator");
        return new BeefBurger();
    }

    @Override
    public Packer packBurger() {
        return new PremiumBurgerPack();
    }
}
