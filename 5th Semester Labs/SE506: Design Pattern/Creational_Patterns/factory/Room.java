package factory_pattern;

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

    public void setSide(String direction, IMazeProperties mazeProperties){
        mazePropertiesHashMap.put(roomPosition, mazeProperties);
    }

    public int getRoomNumber() {
        return this.roomNumber;
    }


}
