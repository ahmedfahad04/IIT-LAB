package design_patterns.creational.builder.mealplanner.bottle;

import design_patterns.creational.builder.mealplanner.Packing;

public class Bottle implements Packing {

    @Override
    public String pack() {
        return "Bottle";
    }
}
