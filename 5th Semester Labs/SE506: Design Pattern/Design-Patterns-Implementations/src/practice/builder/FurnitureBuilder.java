package practice.builder;

import practice.builder.chair.WoodenChair;
import practice.builder.table.GlassDiningTable;
import practice.builder.table.WoodenDiningTable;

public class FurnitureBuilder {
    public FurnitureSet defaultWoodenFurnitureSet() {
        FurnitureSet furnitureSet = new FurnitureSet(new WoodenDiningTable());
        for (int i = 0; i < 6; i++) {
            furnitureSet.addChair(new WoodenChair());
        }
        return furnitureSet;
    }

    public FurnitureSet defaultGlassFurnitureSet() {
        FurnitureSet furnitureSet = new FurnitureSet(new GlassDiningTable());
        for (int i = 0; i < 6; i++) {
            furnitureSet.addChair(new WoodenChair());
        }
        return furnitureSet;
    }
}
