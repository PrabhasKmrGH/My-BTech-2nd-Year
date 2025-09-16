import java.util.Scanner;

public class W09_P5{

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        double x1 = sc.nextDouble();
        double y1 = sc.nextDouble();
        double x2 = sc.nextDouble();
        double y2 = sc.nextDouble();
        sc.close();

        Point p1 = new Point(x1, y1);
        Point p2 = new Point(x2, y2);

        System.out.print(p1.distance(p2));
    }
}

// Note: Pass objects of type class Point as argument in distance() method.
class Point {
    double x, y;

    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    double distance(Point p) {
        return Math.sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
}