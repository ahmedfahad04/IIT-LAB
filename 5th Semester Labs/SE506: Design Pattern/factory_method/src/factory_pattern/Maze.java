package factory_pattern;

import java.util.ArrayList;
import java.util.List;

public class Maze {

    List<Room> roomList = new ArrayList<>();

    public Maze(){

    };

    public void addRoom(Room room){
        roomList.add(room);
    }

    public void showDetails() {
        System.out.println("Total feature_pattern.Room Created: "+ roomList.size());
    }
}
