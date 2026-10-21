package design_patterns.creational.builder.mealplanner.bottle;

import design_patterns.creational.builder.mealplanner.Item;
import design_patterns.creational.builder.mealplanner.Packing;

public abstract class ColdDrink implements Item {
    @Override
    public Packing packing() {
        return new Bottle();
    }

    @Override
    public abstract float price();
}
