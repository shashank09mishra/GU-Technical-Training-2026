
import java.util.Scanner;

public class problem1 {
public static void weights(int[] nums){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int[] arr=new int[nums.length];
    int prefix = 0;
    int suffix = n - 1;
    int mid = n / 2;
    int count=0;
    while (prefix < mid && suffix > mid) {
    if (nums[prefix] == nums[mid] && nums[suffix] == nums[mid])
    return ;
    }
    else if (nums[prefix] == nums[mid] && nums[suffix] < nums[mid]) {
    return;
    }
    else if (nums[prefix] < nums[mid] && nums[suffix] == nums[mid]) {
    return;
    }
    else {
   return ;
   }
   while (prefix < mid) {
   if (nums[prefix] == nums[mid]) {
   count++;
   prefix++;
    }
    else {
    prefix++;
    }
    }
    while (suffix > mid) {
    if (nums[suffix] == nums[mid]) {
    count++;
    suffix--;}
    else {
    suffix--;}
                        }
   if (count == n - 1) {
   return ;
                            }
   else {
    return ;
    }
    }
                                
}

    
