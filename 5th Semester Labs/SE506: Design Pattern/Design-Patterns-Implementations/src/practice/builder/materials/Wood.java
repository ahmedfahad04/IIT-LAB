package practice.builder.materials;

import practice.builder.Material;

public class Wood implements Material {
    @Override
    public String typeOfMaterial() {
        return "Wooden";
    }
}
