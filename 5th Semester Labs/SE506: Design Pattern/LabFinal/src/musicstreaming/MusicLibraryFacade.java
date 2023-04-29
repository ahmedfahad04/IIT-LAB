package musicstreaming;

import java.util.ArrayList;
import java.util.List;

public class MusicLibraryFacade {

    List<MusicItems> playlists = new ArrayList<>();


    public void createPlaylist(String plyaListName){
        this.playlists.add(new Playlist(plyaListName));
    }

    public void deletePlayList(String playListName) {
        this.playlists.remove(new Playlist(playListName));
    }

    public void addSong(String songName) {
        this.playlists.add(new Song(songName));
    }

    public void removeSong(String songName) {
        this.playlists.remove(new Song(songName));
    }

    public void playMusic() {
        for(MusicItems item: this.playlists) {
            if(item instanceof Playlist) {
                ((Playlist) item).play();
            }
        }
    }
}
