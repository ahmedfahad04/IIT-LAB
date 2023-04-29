package Builder_Pattern;

public class Main {
    public static void main(String[] args) {
        CarBuilder newCarBuilder = new CarBuilder();
        Director engineer = new Director(newCarBuilder);
        engineer.buildCorolla();


        Car car = newCarBuilder.getCar();
        System.out.println(car);

    }
}
