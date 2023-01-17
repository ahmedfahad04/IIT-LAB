package factory_pattern;

public class BombedMazeGame extends MazeGame{
    public BombedMazeGame() {
        System.out.println("BombedMazeGame created");
    }

    public Wall MakeWall() {
        return new BombedWall();
    }

    public Room MakeRoom(int n) {
        return new RoomWithBomb(n);
    }
}
