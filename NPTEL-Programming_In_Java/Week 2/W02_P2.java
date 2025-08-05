import java.util.Scanner;

public class W02_P2 {
  public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
  
  // Read length and width of the rectangle
  int length = sc.nextInt();
  int width = sc.nextInt();
  // Complete the code to calculate the perimeter of the rectangle
  
  // Calculate the perimeter using the correct formula
  int perimeter = 2 * (length + width);
  
  /*
   Hint:
   The formula is: perimeter = 2 multiplied by (length + width)
   */
  System.out.println("Perimeter is: " + perimeter);
  
  sc.close();
  }
}

