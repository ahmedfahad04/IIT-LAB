package design_patterns.creational.builder.mealplanner.burger;

import design_patterns.creational.builder.mealplanner.Item;
import design_patterns.creational.builder.mealplanner.Packing;

public abstract class Burger implements Item {

    @Override
    public Packing packing() {
        return new Wrapper();
    }

    @Override
    public abstract float price();

}
