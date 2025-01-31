import java.util.Scanner;

public class PrintAllNumbersInLimit 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter lower limit: ");
        int lowerLimit = sc.nextInt();
        
        System.out.print("Enter upper limit: ");
        int upperLimit = sc.nextInt();
        
        if(upperLimit>lowerLimit)
        {
            for(int limit = lowerLimit+1 ; limit < upperLimit ; limit++)
            {
                System.out.println(limit);
            }
        }
        else
        {
            System.out.println("Invalid limit");
        }
        sc.close();
    }
}
