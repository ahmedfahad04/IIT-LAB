package Strategy_Pattern;

public class Addition implements CalculatorOperation{
    
    private float number_1;
    private float number_2;
    public float result;

    public Addition(int number_1, int number_2) {
        this.number_1 = number_1;
        this.number_2 = number_2;
    }

    @Override
    public void perform() {
        this.result = number_1 + number_2;
        System.out.println("The result of the addition is: " + this.result);    
    }

}
