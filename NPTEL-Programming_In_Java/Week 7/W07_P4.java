import java.util.Scanner;

class PrintNumbers implements Runnable {
    private int start;
    private int end;

    // Create a constructor of this class that takes two private parameters (start and end)
    public PrintNumbers(int start, int end) {
        this.start = start;
        this.end = end;
    }

    // Create Run() method
    @Override
    public void run() {
        for (int i = start; i <= end; i += 2) {
            System.out.println(Thread.currentThread().getName() + ": " + i);
        }
    }
}

class W07_P4 {
    // Code to create two threads, one printing even numbers and the other printing odd numbers
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // System.out.print("Enter the starting value for even numbers: ");
        int evenStart = scanner.nextInt();
        // System.out.print("Enter the ending value for even numbers: ");
        int evenEnd = scanner.nextInt();
        // System.out.print("Enter the starting value for odd numbers: ");
        int oddStart = scanner.nextInt();
        // System.out.print("Enter the ending value for odd numbers: ");
        int oddEnd = scanner.nextInt();

        Thread evenThread = new Thread(new PrintNumbers(evenStart, evenEnd), "EvenThread");
        Thread oddThread = new Thread(new PrintNumbers(oddStart, oddEnd), "OddThread");

        evenThread.start();
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        oddThread.start();

        scanner.close();
    }
}