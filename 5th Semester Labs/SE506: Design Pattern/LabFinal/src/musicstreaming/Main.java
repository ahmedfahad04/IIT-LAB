package musicstreaming;


public class Main {
    public static void main(String[] args) {
        MusicLibraryFacade player = new MusicLibraryFacade();
        player.addSong("hhss.mp3");
        player.createPlaylist("ls1");
        player.playMusic();
    }
}
