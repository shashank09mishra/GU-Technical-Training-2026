//  time complexity -> O(nlogn)
// space complexity -> O(1)

import java.util.Arrays;
import java.util.Scanner;

public class Problem3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] ranks = new int[n];

        for(int i=0; i<n; i++){
            ranks[i] = sc.nextInt();
        }

        int cars = sc.nextInt();
        sc.close();

        int start = 1; 
        int end = cars;
        Arrays.sort(ranks);

        int ans = Integer.MAX_VALUE;
        while(start<=end){
            int mid = (start+end)/2;
            int time = timeTaken(ranks, mid, cars);
            if(time!=-1){
                start = mid+1;
                ans = Math.min(ans, time);
            }
            else{
                end = mid-1;
            }
        }

        System.out.println(ans);
    }

    private static int timeTaken(int[] ranks, int mid, int cars) {
        int count = 0;
        int i = ranks.length - 1;
        int max = 0;
        while (cars > 0) {
            count++;
            cars -= mid;
            
            int time = ranks[i] * mid * mid;
            if (max < time) {
                max = time;
            }
            i--;
            if (cars < mid || i == 0) {
                mid = cars;
            }
        }
        if (count == ranks.length) {
            return max;
        } else {
            return -1;
        }
    }
}
