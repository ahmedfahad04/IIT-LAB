package builder_pattern;

import java.util.ArrayList;
import java.util.List;

public class Maze {

    List<Integer> roomList = new ArrayList<>();

    public Maze(){

    };

    public void addRoom(int n){
        roomList.add(n);
    }

    public void showDetails() {
        System.out.println("Total feature_pattern.Room Created: "+ roomList.size());
    }

    public Room RoomNo(int room){
        return new Room(room);
    }
}
