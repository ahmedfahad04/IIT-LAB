package design_patterns.structural.adapter;

public class VlcPlayer implements AdvancedMediaPlayer{
    @Override
    public void playVlc(String filename) {
        System.out.println("Playing vlc file. Name: " +filename);
    }

    @Override
    public void playMp4(String filename) {
        // Do Nothing
    }
}
