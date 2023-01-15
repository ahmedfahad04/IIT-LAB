package factory_pattern;

public class EnchantedMazeGame extends MazeGame{
    public EnchantedMazeGame() {};

    public Room MakeRoom(int n) {
        return new EnchantedRoom(n);
    }

    public Door MakeDoor(Room r1, Room r2 ) {
        return new DoorNeedingSpell(r1, r1);
    }
}
