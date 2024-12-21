import java.util.Scanner;

class SumOfTwoNumbers {
   SumOfTwoNumbers() {
   }

   public static void main(String[] args) {

      Scanner sc = new Scanner(System.in);

      int var2 = sc.nextInt();
      int var3 = sc.nextInt();
      int var4 = var2 + var3;

      System.out.println(var4);
   }
}