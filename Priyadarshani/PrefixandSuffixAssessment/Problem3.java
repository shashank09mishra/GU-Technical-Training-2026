import java.util.Arrays;

public class matrixSum2d {
    public int[][] prefixsum;

    public int[][] NumArray(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        this.prefixsum= new int[m + 1][n + 1];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixsum[i][j] = matrix[i - 1][j - 1] 
                                + prefixsum[i - 1][j] 
                                + prefixsum[i][j - 1] 
                                - prefixsum[i - 1][j - 1];
            }
        }
        return prefixsum;
    }
    public static void main(String[] args) {
        int[][] matrix= {{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}};
        matrixSum2d obj= new matrixSum2d();
        System.out.println(Arrays.deepToString(obj.NumArray(matrix)));
    }
}
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
