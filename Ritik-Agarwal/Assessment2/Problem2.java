// time complexity -> O(nlogn) ; n->length of array
// space complexity -> O(1)

import java.util.Scanner;

public class Problem2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] bananas = new int[n];
        for(int i=0; i<n; i++){
            bananas[i] = sc.nextInt();
        }
        int hours = sc.nextInt();
        sc.close();

        int totalBananas = 0;
        for(int i:bananas){
            totalBananas+=i;
            
        }

        int start = 0;
        int end = totalBananas;

        while(start<=end){
            int mid = (start+end)/2;
            if(isPossible(bananas, mid, hours)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        System.out.println(start);
    }
    private static boolean isPossible(int[] bananas, int mid, int hours){
        for(int i=0; i<bananas.length; i++){
            int hrs = (bananas[i])/mid;
            if(bananas[i]%mid>0){
                hrs++;
            }
            hours-=hrs;
        }
        return hours>=0;
    }
}
