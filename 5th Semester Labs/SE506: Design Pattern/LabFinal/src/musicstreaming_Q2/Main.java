package musicstreaming_Q2;

public class Main {
    public static void main(String[] args) {
        ConcreteArtist artist1 = new ConcreteArtist("Jackson");
        artist1.artist.registerUser(new ConcreteUser("Akash"));
        artist1.artist.registerUser(new ConcreteUser("Bob"));
        artist1.releaseSong(new Song("My sky gone.mp3"));
    }
}
