package factory;

public class client {
    public static void main(String[] args) {

        // In that case, we must have one product class
        // here product class are Window and ScrollBar

        MazeGame mazeGame = new BombedMazeGame();   // thats the actual use case, where overridden factory method is used
        Maze maze = mazeGame.createMaze();  // due to operational method, it's optional
        maze.showDetails();
    }
}
