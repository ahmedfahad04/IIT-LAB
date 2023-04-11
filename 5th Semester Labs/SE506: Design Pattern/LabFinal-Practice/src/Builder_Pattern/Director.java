package Builder_Pattern;

public class Director {

    Builder builder;

    public Director(Builder builder)  {
        this.builder = builder;
    }

    public Car getCar() {
        return this.builder.build();
    }


    public void buildCorolla(Builder builder) {
        this.builder.carId(5);
        this.builder.carName("Corolla");
        this.builder.carModel("X");
    }
    public void buildPajero(Builder builder) {
        this.builder.carId(15);
        this.builder.carName("Pajero");
        this.builder.carModel("X11");
    }
}
