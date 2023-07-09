package builder_pattern;

public class StandardMazeBuilder extends MazeBuilder {

    private Maze currentMaze;

    private Direction CommonWall(Room room, Room room2) {
        return null;
    }

    public StandardMazeBuilder(){
        currentMaze = null;
        System.out.println("StandardMazeBuilder");
    };

    @Override
    public void BuildMaze() {
        currentMaze = new Maze();
    }

    @Override
    public void BuildRoom(int n) {
        if(currentMaze.RoomNo(n) != null){
            Room room = new Room(n);
            currentMaze.addRoom(n);

            room.setSide(new Direction("North"), new Wall());
            room.setSide(new Direction("South"), new Wall());
            room.setSide(new Direction("East"), new Wall());
            room.setSide(new Direction("West"), new Wall());
        }
        
    }

    @Override
    public void BuildDoor(int n1, int n2) {
        Room r1 = currentMaze.RoomNo(n1);
        Room r2 = currentMaze.RoomNo(n2);
        Door door = new Door(r1, r2);

        r1.setSide(CommonWall(r1, r2), (IMazeProperties) door);
        r2.setSide(CommonWall(r2, r1), (IMazeProperties) door);
        
    }

    @Override
    public Maze GetMaze() {
        return currentMaze;
    }
    
}
