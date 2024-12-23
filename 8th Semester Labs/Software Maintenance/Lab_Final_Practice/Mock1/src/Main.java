public class Main {
    public static void main(String[] args) {
        Department itDepartment = new Department("IT");

        Employee emp1 = new Employee("Alice", 101, 50000);
        Employee emp2 = new Employee("Bob", 102, 60000);

        itDepartment.addEmployee(emp1);
        itDepartment.addEmployee(emp2);

        System.out.println("Employees in IT Department:");
        itDepartment.displayEmployees();

        Employee foundEmployee = itDepartment.findEmployeeById(1401);
        if (foundEmployee != null) {
            System.out.println("Employee found: " + foundEmployee);
        } else {
            System.out.println("No employee with id 1401 found.");
        }
    }
}
