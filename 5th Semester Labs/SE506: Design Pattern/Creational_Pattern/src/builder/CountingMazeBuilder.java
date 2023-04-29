package builder;

public class CountingMazeBuilder extends MazeBuilder {

    public CountingMazeBuilder() {
        System.out.println("CountingMazeBuilder");
    }

    @Override
    public void BuildMaze() {
        
    }

    @Override
    public void BuildRoom(int room) {        
    }

    @Override
    public void BuildDoor(int roomFrom, int roomTo) {        
    }

    @Override
    public Maze GetMaze() {
        return null;
    }

    public void GetCounts(int a, int b){
        
    };

    
}
