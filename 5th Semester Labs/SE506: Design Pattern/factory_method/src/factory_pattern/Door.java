package factory_pattern;

public class Door implements IMazeProperties{

    Room room1;
    Room room2;

    public Door(Room room1, Room room2) {
        this.room1 = room1;
        this.room2 =  room2;
    }
    public void MakeDoor(Room r1, Room r2) {
        return;
    }
}
