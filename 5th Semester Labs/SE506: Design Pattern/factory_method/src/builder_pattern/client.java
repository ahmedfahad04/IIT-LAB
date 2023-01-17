package builder_pattern;

// package builder_pattern;

public class client {
    public static void main(String args[]){
        Maze maze = new Maze();
        MazeGame game = new MazeGame();
        StandardMazeBuilder builder = new StandardMazeBuilder();

        game.createMaze(builder);
        maze = builder.GetMaze();
    }
}
