package design_patterns.structural.adapter;

public class Driver {
    public static void main(String[] args) {
        AudioPlayer audioPlayer = new AudioPlayer();

        audioPlayer.play("mp3", "Audio");
        audioPlayer.play("mp4", "tomar jonne Nilche Tara");
        audioPlayer.play("vlc", "Peacemaker");
    }
}
