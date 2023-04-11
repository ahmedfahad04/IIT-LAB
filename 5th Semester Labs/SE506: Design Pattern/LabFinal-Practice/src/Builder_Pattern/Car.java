package Builder_Pattern;

public class Car extends CarPlan{

    private int carId;
    private String carName;
    private String carModel;
    private String carColor;

    public Car() {
    }

    @Override
    public String toString() {
        return "Car{" +
                "carId=" + carId +
                ", carName='" + carName + '\'' +
                ", carModel='" + carModel + '\'' +
                ", carColor='" + carColor + '\'' +
                '}';
    }

    @Override
    public void setCarId(int carId) {
        this.carId = carId;
    }

    @Override
    public void setCarName(String carName) {
        this.carName = carName;
    }

    @Override
    public void setCarModel(String carModel) {
        this.carModel = carModel;
    }

    @Override
    public void setCarColor(String carColor) {
        this.carColor = carColor;
    }
}
