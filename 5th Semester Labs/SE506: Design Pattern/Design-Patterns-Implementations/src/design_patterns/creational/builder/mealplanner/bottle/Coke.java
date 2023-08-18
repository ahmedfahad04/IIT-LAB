package design_patterns.creational.builder.mealplanner.bottle;

public class Coke extends ColdDrink{
    @Override
    public String name() {
        return "Coke";
    }

    @Override
    public float price() {
        return 20.0f;
    }
}
