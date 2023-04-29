package musicstreaming_Q1;

public class MusicPlayer {

    private MusicItems items;

    public void addToPlaylist(MusicItems musicItems){
        new CompositePlaylist(musicItems);
    }

}
