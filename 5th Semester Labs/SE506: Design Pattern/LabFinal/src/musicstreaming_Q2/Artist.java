package musicstreaming_Q2;

import java.util.ArrayList;
import java.util.List;

public class Artist {
	private String name;

	private List<User> users = new ArrayList<>();
	private List<Song> releasedSongs;


	public Artist(String name) {
		super();
		this.name = name;
		this.releasedSongs = new ArrayList<Song>();
	}

	public void registerUser(User user) {
		this.users.add(user);
	}

	public void removeUser(User user) {
		this.users.remove(user);
	}

	public String getName() {
		return this.name;
	}

	public void NotifyUser() {
		for(User user: users){
			user.update(this);
		}
	}
}
