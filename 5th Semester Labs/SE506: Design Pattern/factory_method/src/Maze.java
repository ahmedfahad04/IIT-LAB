import java.util.ArrayList;
import java.util.List;

public class Maze {

    List<Room> roomList = new ArrayList<>();

    public Maze(){

    };

    public void addRoom(Room room){
        roomList.add(room);
    }
}
