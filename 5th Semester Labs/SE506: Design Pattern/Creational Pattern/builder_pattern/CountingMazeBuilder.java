package builder_pattern;

public class CountingMazeBuilder extends MazeBuilder {

    private int doors;
    private int rooms;

    public CountingMazeBuilder() {
        rooms = doors = 0;
    }

    @Override
    public void BuildMaze() {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void BuildRoom(int room) {
        rooms++;        
    }

    @Override
    public void BuildDoor(int roomFrom, int roomTo) {
        doors++;        
    }

    @Override
    public Maze GetMaze() {
        // TODO Auto-generated method stub
        return null;
    }

    public void GetCounts(int a, int b){
        
    };

    
}
