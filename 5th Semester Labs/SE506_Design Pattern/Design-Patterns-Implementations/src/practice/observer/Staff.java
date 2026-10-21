package practice.observer;

public class Staff extends People{
    public Staff(Office office) {
        this.office = office;
        this.office.attach(this);
    }

    @Override
    public void update() {
        System.out.println("Staff news: " + office.getNews());
    }
}
