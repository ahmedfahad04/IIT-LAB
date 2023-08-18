package practice.builder.chair;

import practice.builder.Material;
import practice.builder.materials.Wood;

public class WoodenChair extends Chair {
    @Override
    public Material material() {
        return new Wood();
    }

    @Override
    public String name() {
        return "Wooden Chair";
    }

    @Override
    public double price() {
        return 20.0f;
    }
}
