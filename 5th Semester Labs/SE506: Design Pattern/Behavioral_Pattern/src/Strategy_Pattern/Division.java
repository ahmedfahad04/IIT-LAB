package Strategy_Pattern;

public class Division implements CalculatorOperation{
    
    private float number_1;
    private float number_2;
    public float result;

    public Division(int number_1, int number_2) {
        this.number_1 = number_1;
        this.number_2 = number_2;
    }

    @Override
    public void perform() {
        if (number_2 != 0)
        this.result = number_1 / number_2; 
        System.out.println("The result of the division is: " + this.result);
    }

}
