package practice.builder;

public class Driver {
    public static void main(String[] args) {
        FurnitureBuilder builder = new FurnitureBuilder();

        FurnitureSet f1 = builder.defaultWoodenFurnitureSet();
        FurnitureSet f2 = builder.defaultGlassFurnitureSet();

        f1.showSet();
        System.out.println();
        f2.showSet();
    }
}
