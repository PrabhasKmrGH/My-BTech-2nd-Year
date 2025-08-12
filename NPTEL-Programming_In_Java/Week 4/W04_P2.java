import java.util.Scanner;

public class W04_P2 {

    // Declare class Car with a public member variable
    static class Car {
        public int speed; // Public access, can be accessed from outside the class
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read speed value
        int s = sc.nextInt();

        // Create Car object
        Car c = new Car();

        // Assign speed to the object
        c.speed = s;

        // Print the speed using the object
        System.out.print("Speed is: "+c.speed);

        sc.close();
    }
}