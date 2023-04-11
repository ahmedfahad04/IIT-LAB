package Builder_Pattern;

public class Main {
    public static void main(String[] args) {
        CarBuilder newCar = new CarBuilder();
        Director engineer = new Director(newCar);
        engineer.buildCorolla(newCar);

        Car car = newCar.build();
        System.out.println(car);

    }
}
