package practice.observer;

public class Driver {
    public static void main(String[] args) {
        Office iitoffice = new Office();
        Office registeroffice = new Office();

        new Student(iitoffice);
        new Teacher(iitoffice);
        new Staff(iitoffice);

        new Student(registeroffice);
//        new Staff(registeroffice);

        iitoffice.setNews("IIT FAMILY PICNIC SOON");

        registeroffice.setNews("Semester 4 result published");
    }
}
