package design_patterns.creational.builder.mealplanner.burger;

import design_patterns.creational.builder.mealplanner.Packing;

public class Wrapper implements Packing {
    @Override
    public String pack() {
        return "Wrapper";
    }
}
