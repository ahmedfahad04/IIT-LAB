package Strategy_Pattern;

public class Main {
    public static void main(String[] args) {
                
        // Strategy Classes
        // And each concrete strategy class implements the strategy interface
        // CalculatorOperation add = new Addition(10, 20);
        // CalculatorOperation multiply = new Multiplication(5, 7);
        // CalculatorOperation divide = new Division(10,2);
        CalculatorOperation subtract = new Substraction(25,30);
        
        // Context Class
        Calculator calculator = new Calculator(subtract);

        // Context Interface
        calculator.calculate();
    }
}
