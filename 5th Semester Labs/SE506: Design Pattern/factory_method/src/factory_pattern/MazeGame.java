package factory_pattern;

public class MazeGame {

    public Maze createMaze() {
        Maze aMaze = MakeMaze();

        Room r1 = MakeRoom(1);
        Room r2 = MakeRoom(2);

        Door theDoor = MakeDoor(r1, r2);

        aMaze.addRoom(r1);
        aMaze.addRoom(r2);

        r1.setSide("North", MakeWall());
        r1.setSide("East", theDoor);
        r1.setSide("South", MakeWall());
        r1.setSide("West", MakeWall());

        r2.setSide("North", MakeWall());
        r2.setSide("East", MakeWall());
        r2.setSide("South", MakeWall());
        r2.setSide("West", theDoor);

        return aMaze;

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

    public static void main(String[] args) {
        BombedMazeGame bombedMazeGame = new BombedMazeGame();
        Maze maze = bombedMazeGame.createMaze();
        maze.showDetails();
    }
}
