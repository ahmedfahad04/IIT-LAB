package design_patterns.creational.builder.mealplanner;

public class MealSummary{

    private Meal meal;

    public MealSummary() {
    }

    public MealSummary(Meal meal) {
        meal = this.meal;
    }

    public void setMeal(Meal meal) {
        this.meal = meal;
    }

    public void summary(Meal meal){
        setMeal(meal);
        System.out.println("-------------x-----------");
        System.out.println("\nTOTAL ITEMS   :");
        meal.showItems();
        System.out.println("TOTAL PRICE     : "+ meal.getCost());
        System.out.println("-------------x-----------");
    }
}
