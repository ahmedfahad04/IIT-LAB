package practice.builder.chair;

import practice.builder.Furniture;
import practice.builder.Material;
import practice.builder.materials.Wood;

public abstract class  Chair implements Furniture {
    public Material material(){
        return new Wood();
    }

}
