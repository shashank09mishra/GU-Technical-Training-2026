import java.util.Scanner;

public class q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your radius ");
        int r  = sc.nextInt();
        double area = (3.14*(r*r));
        double circumference = 2*3.14*r;
        System.out.println("The area of the circle is " + area);
        System.out.println("The circumference of circle is " +circumference);

    }
}
