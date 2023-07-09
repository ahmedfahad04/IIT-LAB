package Builder_Pattern;

public class Director {

    Builder builder;

    public Director(Builder builder)  {
        this.builder = builder;
    }


    public void buildCorolla() {
        this.builder.carId(5);
        this.builder.carName("Corolla");
        this.builder.carModel("X");
    }
    public void buildPajero() {
        this.builder.carId(15);
        this.builder.carName("Pajero");
        this.builder.carModel("X11");
    }
}
