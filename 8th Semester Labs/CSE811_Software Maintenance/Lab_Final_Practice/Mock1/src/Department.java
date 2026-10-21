import java.util.ArrayList;

public class Department {
    private String departmentName;
    private ArrayList<Employee> employees;

    public Department(String departmentName) {
        this.departmentName = departmentName;
        this.employees = new ArrayList<>();
    }

    public void addEmployee(Employee emp) {
        employees.add(emp);
    }

    public ArrayList<Employee> getEmployees() {
        return employees;
    }

    public Employee findEmployeeById(int id) {
        for (Employee emp: employees) {
            if (emp.getId() == id) {
                return emp;
            }
        }

        return null;
    }

    public void displayEmployees() {
        int count = employees.toArray().length;
        for (Employee emp : employees) {
            System.out.println(emp);
        }

        System.out.println("Total Employee: " + count);
    }
}
