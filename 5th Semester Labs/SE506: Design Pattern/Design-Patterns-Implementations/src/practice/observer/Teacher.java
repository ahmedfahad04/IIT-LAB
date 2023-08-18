package practice.observer;

public class Teacher extends People{
    public Teacher(Office office) {
        this.office = office;
        this.office.attach(this);
    }

    @Override
    public void update() {
        System.out.println("Teacher news: " + office.getNews());
    }
}
