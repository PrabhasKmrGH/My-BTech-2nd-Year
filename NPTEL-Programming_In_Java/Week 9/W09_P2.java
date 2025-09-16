import java.util.Scanner;
public class W09_P2{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine(); // Read as string, e.g., 5+6

        // Declare and initialize the required variable(s)
        int operand1 = 0, operand2 = 0, result = 0;
        char operator = ' ';

        // Split the input string into character array
        char[] chars = input.toCharArray();

        // Separate two operands and operator
        String num1 = "", num2 = "";
        boolean second = false;
        for(char c : chars){
            if(c == '+' || c == '-' || c == '*' || c == '/'){
                operator = c;
                second = true;
            } else {
                if(!second){
                    num1 += c;
                } else {
                    num2 += c;
                }
            }
        }

        operand1 = Integer.parseInt(num1);
        operand2 = Integer.parseInt(num2);

        // Perform the required operation
        switch(operator){
            case '+': result = operand1 + operand2; break;
            case '-': result = operand1 - operand2; break;
            case '*': result = operand1 * operand2; break;
            case '/':
                if(operand2 != 0)
                    result = operand1 / operand2;
                break;
        }

        // Print the output as stated in the question
        System.out.println(input + " = " + result);
    } // The main() method ends here
} // The main class ends here