package design_patterns.creational.builder.mealplanner;

import design_patterns.creational.builder.mealplanner.bottle.Coke;
import design_patterns.creational.builder.mealplanner.bottle.Pepsi;
import design_patterns.creational.builder.mealplanner.burger.ChickenBurger;
import design_patterns.creational.builder.mealplanner.burger.VegBurger;

public class MealBuilder {
    public Meal prepareVegMeal(){
        Meal meal = new Meal();
        meal.addItem(new VegBurger());
        meal.addItem(new Coke());
        return meal;
    }

    public Meal prepareNonVegMeal(){
        Meal meal = new Meal();
        meal.addItem(new ChickenBurger());
        meal.addItem(new Pepsi());
        return meal;
    }
}
