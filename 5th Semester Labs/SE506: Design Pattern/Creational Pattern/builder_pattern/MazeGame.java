package builder_pattern;

public class MazeGame {

    public Maze createMaze(MazeBuilder builder) {
        builder.BuildMaze();
        builder.BuildRoom(1);
        builder.BuildRoom(2);
        builder.BuildDoor(1, 2);
        return builder.GetMaze();
    }

    public Maze CreateComplexMaze(MazeBuilder builder) {
        builder.BuildRoom(1);
        // ...
        builder.BuildRoom(1001);
        return builder.GetMaze();
    }

    // factory method

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
