import java.math.BigDecimal;

public class Employee {
    private String name;
    private int id;
    private BigDecimal salary;

    public Employee(String name, int id, double salary) {
        this.name = name;
        this.id = id;
        this.salary = new BigDecimal(salary);
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public BigDecimal getSalary() {
        BigDecimal inputSalary = new BigDecimal(String.valueOf(salary));
        if (inputSalary.compareTo(BigDecimal.ZERO) < 0) {
            return BigDecimal.ZERO;
        } else {
            return salary;
        }
    }

    public void setSalary(double salary) {
        this.salary =  new BigDecimal(salary);
    }

    @Override
    public String toString() {
        return "Employee [ID: " + id + ", Name: " + name + ", Salary: " + salary + "]";
    }
}
