package factory;

public class MazeGame {

    public Maze createMaze() {
        Maze aMaze = MakeMaze();

        Room r1 = MakeRoom(1);
        Room r2 = MakeRoom(2);

        aMaze.addRoom(r1);
        aMaze.addRoom(r2);

        r1.setSide("North", MakeWall());
        r1.setSide("East", MakeDoor(r1, r2));
        r1.setSide("South", MakeWall());
        r1.setSide("West", MakeWall());

        r2.setSide("North", MakeWall());
        r2.setSide("East", MakeWall());
        r2.setSide("South", MakeWall());
        r2.setSide("West", MakeDoor(r1, r2));

        return aMaze;
    }

    // factory method (virtual function that will be overriden by derived class)
    
    public Maze MakeMaze(){
        return new Maze();
    };

    public Room MakeRoom(int n) {
        return new Room(n);
    }

    public Wall MakeWall() {
        return new Wall();
    }

    public Door MakeDoor(Room r1, Room r2) {
        return new Door(r1, r2);
    }
}