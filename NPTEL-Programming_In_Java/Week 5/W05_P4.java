//Prefixed Fixed Code:
import java.util.Scanner;
import java.util.InputMismatchException;

public class W05_P4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int length = sc.nextInt();
        // create an array to save user input
        int[] name = new int[length];
        int sum=0; //save the total sum of the array.

        /*
        Define try-catch block to save user input in the array "name"
        If there is an exception then catch the exception otherwise print the total sum of the array.
        */

        try {
            for(int i=0; i<length; i++){
                name[i] = sc.nextInt();
                sum += name[i];
            }
            // traverse the array to find the total sum of the array.
            System.out.print(sum);
        }
        catch (InputMismatchException e) {
            System.out.print("You entered bad data.");
        }
    }
}