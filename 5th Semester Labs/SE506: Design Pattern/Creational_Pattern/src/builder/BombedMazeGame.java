package builder;

public class BombedMazeGame extends MazeGame{
    public BombedMazeGame() {
        System.out.println("BombedMazeGame created");
    }

    public BombedWall MakeWall() {
        return new BombedWall();
    }

    public RoomWithBomb MakeRoom(int n) {
        return new RoomWithBomb(n);
    }
}
