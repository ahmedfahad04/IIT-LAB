package factory_pattern;

public class EnchantedRoom extends Room{
    public EnchantedRoom(int roomNumber) {
        super(roomNumber);
        System.out.println("Enchanted Room");
    }
}
