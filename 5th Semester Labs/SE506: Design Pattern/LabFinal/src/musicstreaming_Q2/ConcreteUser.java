package musicstreaming_Q2;

public class ConcreteUser extends User {

    private String name;

    public ConcreteUser(String name) {
        super(name);
        this.name = name;
    }

    @Override
    public void update(Artist artist) {
        System.out.println("From:" + this.name +">> "+ artist.getName() + ": " + "Released a song...");
    }


}
