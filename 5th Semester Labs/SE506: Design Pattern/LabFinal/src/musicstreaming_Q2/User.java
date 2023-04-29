package musicstreaming_Q2;

public abstract class User {
	private String name;

	public User(String name) {
		this.name = name;
	}

	public abstract void  update(Artist artist);
}
