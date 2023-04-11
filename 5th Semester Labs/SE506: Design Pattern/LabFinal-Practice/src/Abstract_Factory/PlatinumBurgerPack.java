package Abstract_Factory;

public class PlatinumBurgerPack implements Packer{
    @Override
    public void pack() {
        System.out.println("... Platinum packing ...");
    }
}
