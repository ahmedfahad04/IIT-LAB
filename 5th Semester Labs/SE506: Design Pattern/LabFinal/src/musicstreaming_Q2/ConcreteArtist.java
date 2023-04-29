package musicstreaming_Q2;

import java.util.ArrayList;
import java.util.List;

public class ConcreteArtist {

    Artist artist;

    private List<Song> releasedSongs;

    public ConcreteArtist(String name) {
        this.artist = new Artist(name);
        this.releasedSongs = new ArrayList<Song>();
    }

    public void releaseSong(Song song) {
        releasedSongs.add(song);
        artist.NotifyUser();
    }

}
