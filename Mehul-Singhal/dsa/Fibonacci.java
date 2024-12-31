class Solution {
    //TOP DOWN APPROACH USING RECURSION(DFS/Stack)
    /*public int fibo(int n,int[] dp) {
        if(n<=1){
            return dp[n] =n;

        }
        else if(dp[n]!= -1){
            return dp[n];
        }
            return dp[n]= fibo(n-1,dp) + fibo(n-2,dp);
    }
    public int fib(int n){
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        return fibo(n,dp);
    }
}*/
// BOTTOM UP APPROACH ITERATIVE(BFS/queue)
public int fib(int n){
    int[] dp = new int[n+3];
    dp[0] =0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i =3; i<=n ;i++){
        dp[i] =dp[i-1] +dp[i-2];

    }
    return dp[n];
}
}