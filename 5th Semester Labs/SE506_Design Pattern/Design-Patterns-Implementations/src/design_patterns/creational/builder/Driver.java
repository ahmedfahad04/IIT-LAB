package design_patterns.creational.builder;

import design_patterns.creational.builder.mealplanner.Meal;
import design_patterns.creational.builder.mealplanner.MealBuilder;
import design_patterns.creational.builder.mealplanner.MealSummary;

public class Driver {

    public static void main(String[] args) {
        MealBuilder mealBuilder = new MealBuilder();
        MealSummary mealSummaryTool = new MealSummary();

        Meal vegMeal = mealBuilder.prepareVegMeal();
        mealSummaryTool.summary(vegMeal);

        Meal nonVegMeal = mealBuilder.prepareNonVegMeal();
        mealSummaryTool.summary(nonVegMeal);

    }


}
