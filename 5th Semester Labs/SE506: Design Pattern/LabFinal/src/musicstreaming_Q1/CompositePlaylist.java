package musicstreaming_Q1;

import java.util.ArrayList;
import java.util.List;

public class CompositePlaylist {

    private String title;
    private List<Song> songs = new ArrayList<>();
    private List<MusicItems> items = new ArrayList<>();

    public CompositePlaylist(MusicItems items) {
        this.items.add(items);
    }

    public void play() {
        System.out.println("Playing playlist: " + title);
        for (Song song : songs) {
            song.play();
        }
    }

    public void pause() {
        System.out.println("Pausing playlist: " + title);
        for (Song song : songs) {
            song.pause();
        }
    }

    public void stop() {
        System.out.println("Stopping playlist: " + title);
        for (Song song : songs) {
            song.stop();
        }
    }
}
