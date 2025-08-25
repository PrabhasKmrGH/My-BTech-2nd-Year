import java.util.Scanner;

public class W06_P5 {

    // Method to calculate square root, may throw Exception
    public static double calculateSquareRoot(double num) throws Exception {
        // Throw Exception if number is negative
        if (num < 0) {
            throw new Exception("Negative number");
        }
        // For valid input, return square root
        return Math.sqrt(num);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read input
        double number = sc.nextDouble();

        // Try to calculate square root
        try {
            double result = calculateSquareRoot(number);
            System.out.println("Square root is: " + result);
        } catch (Exception e) {
            System.out.println("Cannot calculate square root of negative number");
        } finally {
            sc.close();
        }
    }
}