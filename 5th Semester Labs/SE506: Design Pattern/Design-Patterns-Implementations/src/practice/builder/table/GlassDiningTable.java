package practice.builder.table;

import practice.builder.Material;
import practice.builder.materials.Glass;

public class GlassDiningTable extends CenterTable{
    @Override
    public Material material() {
        return new Glass();
    }

    @Override
    public String name() {
        return "Glass Dining Table";
    }

    @Override
    public double price() {
        return 500.0f;
    }
}
