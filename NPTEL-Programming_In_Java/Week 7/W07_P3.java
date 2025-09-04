import java.util.Scanner;
public class W07_P3 {
    // Code to create function primeSum(), compute the sum of all prime numbers in a given range.
    public static int primeSum(int x, int y) {
        int sum = 0;
        for (int i = x; i <= y; i++) {
            if (isPrime(i)) {
                sum += i;
            }
        }
        return sum;
    }

    // Helper function to check if a number is prime
    private static boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        System.out.println(primeSum(x, y));
    }
}