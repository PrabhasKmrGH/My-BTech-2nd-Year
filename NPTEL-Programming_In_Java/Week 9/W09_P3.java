import java.util.Scanner;

class SquareThread extends Thread {
    private int begin;
    private int end;

    SquareThread(int begin, int end) {
        this.begin = begin;
        this.end = end;
    }

    // HINT: Some keyword should be added below in the _____ and the program should run correctly
    public void run() {
        // Print the square of each number from begin to end
        // If begin is greater than end,
        // print the square of each number in reverse order from end to begin
        if (begin > end) {
            for (int i = begin; i >= end; i--) {
                System.out.println(i * i);
            }
        } else {
            for (int i = begin; i <= end; i++) {
                System.out.println(i * i);
            }
        }
    }
}

public class W09_P3 {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        // System.out.print("Enter the begin for square calculation: ");
        int begin = scanner.nextInt();
        // System.out.print("Enter the end for square calculation: ");
        int end = scanner.nextInt();
        scanner.close();

        SquareThread thread1 = new SquareThread(begin, end);
        SquareThread thread2 = new SquareThread(end, begin);

        thread1.start();
        thread2.start();
    }
}