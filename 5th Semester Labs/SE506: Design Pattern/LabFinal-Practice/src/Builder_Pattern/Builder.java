package Builder_Pattern;

public interface Builder {
    Builder carId(int id);
    Builder carName(String name);
    Builder carColor(String color);
    Builder carModel(String model);

    Car build();
}
