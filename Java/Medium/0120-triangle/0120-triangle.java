import java.util.*;

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {

        int n = triangle.size();

        int[][] dp = new int[n][n];

        // Base case: copy the last row
        for(int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle.get(n - 1).get(j);
        }

        // Move from bottom to top and simultaneously calculating sum 
        for(int i = n - 2; i >= 0; i--) {

            for(int j = 0; j <= i; j++) {

                int current = triangle.get(i).get(j);

                int left = dp[i + 1][j];
                int right= dp[i + 1][j + 1];

                dp[i][j] =current + Math.min(left, right);
            }
        }
        return dp[0][0];
    }
}