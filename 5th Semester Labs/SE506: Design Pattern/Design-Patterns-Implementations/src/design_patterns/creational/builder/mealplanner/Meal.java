package design_patterns.creational.builder.mealplanner;

import java.util.ArrayList;
import java.util.List;

public class Meal {
    List<Item> items = new ArrayList<Item>();

    public void addItem(Item item){
        items.add(item);
    }

    public float getCost(){
        float cost = 0.0f;
        for (Item item:items) {
            cost += item.price();
        }
        return cost;
    }

    public void showItems(){
        for (Item item:items) {
            System.out.println("Item    : " + item.name());
            System.out.println("Packing : " + item.packing().pack());
            System.out.println("Price   : " + item.price());
            System.out.println();
        }
    }


}
