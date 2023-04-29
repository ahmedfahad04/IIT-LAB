package builder;

import java.util.HashMap;

public class Room implements IMazeProperties{

    int roomNumber;
    String roomPosition;
    HashMap<String, IMazeProperties> mazePropertiesHashMap = new HashMap<>();

    public Room(int roomNumber) {
        this.roomNumber = roomNumber;
    }

    public void MakeRoom(int n) {
        return;
    }

    public void setSide(Direction direction, IMazeProperties mazeProperties){
        mazePropertiesHashMap.put(roomPosition, mazeProperties);
    }

    
}
