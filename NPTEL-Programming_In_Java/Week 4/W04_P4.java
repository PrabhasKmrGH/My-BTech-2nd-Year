import java.util.Scanner;

public class W04_P4 {

    // Declare parent class Employee with a protected member variable
    static class Employee {
        protected int salary; // Protected member
    }

    // Subclass Manager inherits from Employee
    static class Manager extends Employee {
        // No additional members required for this task
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read salary value
        int s = sc.nextInt();

        // Create Manager object
        Manager m = new Manager();

        // Assign salary using the inherited member
        m.salary = s;

        // Print salary
        System.out.print("Salary is: "+m.salary);

        sc.close();
    }
}