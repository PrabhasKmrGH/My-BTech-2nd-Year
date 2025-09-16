import java.util.Scanner;
public class W09_P1{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        // Declare the 5X5 2D array to store the input
        int[][] arr = new int[5][5];

        // Input 2D Array using Scanner Class
        for (int i = 0; i < 5; i++) {
            String line = sc.next();            // e.g., "00001"
            for (int j = 0; j < 5; j++) {
                // store flipped value directly
                arr[i][j] = (line.charAt(j) - '0') ^ 1;  // 0->1, 1->0
            }
        }

        // Output the 2D Flip–Flop Array
        System.out.println();
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(arr[i][j]);
            }
            System.out.println();
        }
    } // The main() ends here
} // The main class ends here