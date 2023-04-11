package Builder_Pattern;

public class CarBuilder implements Builder {
    private int carId;
    private String carName;
    private String carModel;
    private String carColor;

    private Car newCar;

    public CarBuilder(){
        newCar = new Car();
    }


    public Car build() {
        return this.newCar;
    }

    @Override
    public Builder carId(int id) {
        this.newCar.setCarId(id);
        this.carId = id;
        return this;
    }

    @Override
    public Builder carName(String name) {
        this.carName = name;
        return this;
    }

    @Override
    public Builder carColor(String color) {
        this.carColor = color;
        return this;
    }

    @Override
    public Builder carModel(String model) {
        this.carModel = model;
        return this;
    }
}
