package practice.builder;

import practice.builder.chair.Chair;
import practice.builder.table.CenterTable;

import java.util.ArrayList;
import java.util.List;

public class FurnitureSet {
    CenterTable centerTable;
    List<Chair> chairs = new ArrayList<>();

    public FurnitureSet(CenterTable centerTable) {
        this.centerTable = centerTable;
    }

    public void addChair(Chair chair){
        this.chairs.add(chair);
    }

    public void showSet(){
        System.out.println(centerTable.name() +" -> " +centerTable.material().typeOfMaterial() +" -> " + centerTable.price());
        for (Chair chair:chairs) {
            System.out.println(chair.name() + " -> " +chair.material().typeOfMaterial() +" -> " + chair.price());
//            System.out.println(chair.price());
//            System.out.println(chair.material().typeOfMaterial());
        }
    }


}
