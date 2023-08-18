package practice.observer;

public class Student extends People{
    public Student(Office office) {
        this.office = office;
        this.office.attach(this);
    }

    @Override
    public void update() {
        System.out.println("Student news: " + office.getNews());
    }
}
