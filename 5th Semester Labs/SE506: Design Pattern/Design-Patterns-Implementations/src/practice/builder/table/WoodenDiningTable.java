package practice.builder.table;

import practice.builder.Material;
import practice.builder.materials.Wood;

public class WoodenDiningTable extends CenterTable {
    @Override
    public Material material() {
        return new Wood();
    }

    @Override
    public String name() {
        return "Wooden Dining Table";
    }

    @Override
    public double price() {
        return 300.0f;
    }
}
