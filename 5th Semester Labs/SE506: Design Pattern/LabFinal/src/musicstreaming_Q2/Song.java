package musicstreaming_Q2;

public class Song {
	private String title;

	public Song(String title) {
		this.title = title;
	}

	public void play() {
		System.out.println("Playing song: " + title);
	}

	public void pause() {
		System.out.println("Pausing song: " + title);
	}

	public void stop() {
		System.out.println("Stopping song: " + title);
	}
}
