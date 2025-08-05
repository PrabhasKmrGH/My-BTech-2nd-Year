import java.util.*;

public class W03_P1{
  public static void main(String[] args) {
    Scanner inr = new Scanner(System.in);
    int n = inr.nextInt();
    // Add the necessary code in the below space

    // First half: decreasing
    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= i; j++) {
        System.out.print("*");
      }
      System.out.println();
    }
    
    // Second half: increasing
    for (int i = 2; i < n; i++) {
      for (int j = 1; j <= i; j++) {
        System.out.print("*");
      }
      System.out.println();
    }
    
    // Last line (to omit \n for Presentation Error.
    for (int j = 1; j <= n; j++) {
      System.out.print("*");
    }
  }
}
