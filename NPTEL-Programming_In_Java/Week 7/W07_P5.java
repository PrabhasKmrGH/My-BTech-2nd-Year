import java.util.Scanner;

public class W07_P5 {
    private String password;

    // Step 1: Constructor to initialize the password variable
    public W07_P5(String password) {
        this.password = password; // Assign the passed password to the instance variable
    }

    // Method to check if the password is valid
    public boolean isValidPassword(String password) {
        // Step 1: Check if the password length is at least 8 characters
        if (password.length() < 8) {
            return false;
        }

        boolean hasUpper = false;
        boolean hasDigit = false;

        // Step 2: Loop through each character in the password
        for (char ch : password.toCharArray()) {
            if (Character.isUpperCase(ch)) {
                hasUpper = true;
            }
            if (Character.isDigit(ch)) {
                hasDigit = true;
            }
        }

        // Step 3: Return true only if both conditions are satisfied
        return hasUpper && hasDigit;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read password input from user
        String inputPassword = scanner.nextLine();

        W07_P5 validator = new W07_P5(inputPassword);

        // Check password validity and print result
        if (validator.isValidPassword(inputPassword)) {
            System.out.println("Valid Password");
        } else {
            System.out.println("Invalid Password");
        }

        scanner.close();
    }
}