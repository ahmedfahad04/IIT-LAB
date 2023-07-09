package Factory_Method;

// CREATOR CLASS
public abstract class Restaurant {
    public Burger orderBurger() {
        Burger burger = createBurger();
        burger.prepare();
        return burger;
    }

    // I'll get the related burger through this function
    // FACTORY METHOD
    public abstract Burger createBurger();
}
