package Abstract_Factory;

public abstract class Restaurant {

    // I'll get the related burger through this function
    // FACTORY METHOD
    public abstract Burger createBurger();
    public abstract Packer packBurger();
}
