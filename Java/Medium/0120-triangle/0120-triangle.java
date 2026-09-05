import java.util.*;

class Solution {
    
    // Here i is taken as row and j as element in that row 
    public int minPath(List<List<Integer>> triangle,int i, int j, int[][]dp){
        //base case
        if(i == triangle.size()-1){
            return triangle.get(i).get(j);
        }

        if(dp[i][j] != Integer.MAX_VALUE){
            return dp[i][j];
        }

        //current value
        int curr = triangle.get(i).get(j);

        // recursive left
        int left = minPath(triangle, i+1, j, dp);

        //recursive right
        int right = minPath(triangle, i+1, j+1, dp);

        dp[i][j] = curr+Math.min(left,right);

        return dp[i][j];
    }

    public int minimumTotal(List<List<Integer>> triangle) {
        int n=triangle.size();

        int [][] dp = new int [n][n];

        // Mark all states as not calculated
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }

        return minPath(triangle,0,0, dp);
    }

}