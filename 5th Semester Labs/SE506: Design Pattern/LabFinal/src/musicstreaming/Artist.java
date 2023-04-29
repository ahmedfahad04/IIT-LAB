package musicstreaming;

import java.util.ArrayList;
import java.util.List;

public class Artist {
	private String name;
	private List<Song> releasedSongs;

	public Artist(String name) {
		super();
		this.name = name;
		this.releasedSongs = new ArrayList<Song>();
	}

	public void releaseSong(Song song) {
		releasedSongs.add(song);
	}
}
