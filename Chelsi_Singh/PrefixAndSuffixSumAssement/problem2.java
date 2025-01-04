
import java.util.Scanner;

public class problem2 {
public static int[] totalSeats(int[][] nums) {
    Scanner sc=new Scanner(System.in);
    int[] seats = new int[nums.length];
    for (int i = 0; i < nums.length; i++) {
        seats[i] = nums[i][0] + nums[i][1];
        }
        return seats;
    }
}


