package builder;

public class Direction {

    String direction;
    public Direction (String Direction) {
        direction = Direction;
    }

    public Direction CommonWall(Room r1, Room r2){
        return new Direction("Null");
    }
}
