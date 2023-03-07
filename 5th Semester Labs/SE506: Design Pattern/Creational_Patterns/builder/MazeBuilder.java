package builder_pattern;

public abstract class MazeBuilder {

    public MazeBuilder(){};

    public abstract void BuildMaze();
    public abstract void BuildRoom(int room);
    public abstract void BuildDoor(int roomFrom, int roomTo);

    public abstract Maze GetMaze();
    
}
