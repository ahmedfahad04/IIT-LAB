package Abstract_Factory;

public class PremiumBurgerPack implements Packer {
    @Override
    public void pack() {
        System.out.println("..Premium Pack..");
    }
}
