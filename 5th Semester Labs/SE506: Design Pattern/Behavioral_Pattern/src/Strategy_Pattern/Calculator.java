package Strategy_Pattern;

public class Calculator {

    private CalculatorOperation operation;
     
    public Calculator(CalculatorOperation operation){
        this.operation = operation;
    }
    
    public void calculate(){
        operation.perform();
    }

}
