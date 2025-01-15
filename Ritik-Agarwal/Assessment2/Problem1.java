// time complexity -> O(log(n)+n) ; o(log(n)) -> binary search , O(n) -> linear search
// space complexity -> O(1)


import java.util.Scanner;

public class Problem1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] inputArr = new int[n];
        for(int i=0; i<n; i++){
            inputArr[i] = sc.nextInt();
        }
        int target = sc.nextInt();
        sc.close();

        int startIdx = findFirstOccurrence(inputArr, 0, n-1, target);
        int countOccurrence = 0;

        if(startIdx==-1){
            System.out.println("0");
        }
        else{
            while(startIdx<inputArr.length && inputArr[startIdx]==target){
                countOccurrence++;
                startIdx++;
            }
            System.out.println(countOccurrence);
        }
    }

    private static int findFirstOccurrence(int[] inputArr, int start, int end, int target){
        while(start<=end){
            int mid = (start+end)/2;
            if(inputArr[mid]>=target){
                end = mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return start<inputArr.length?start:-1;
    }
}
