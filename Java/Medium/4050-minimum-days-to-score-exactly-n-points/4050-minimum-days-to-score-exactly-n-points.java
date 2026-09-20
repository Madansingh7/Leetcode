class Solution {
    public int minDays(int n) {
       int[] dravonelik = {n};

        int[] dp = new int[n+1];
        Arrays.fill(dp,n+1);
        dp[0]=-1;

        for(int i=0; i<=n; i++){
            if(dp[i]==n+1) continue;

            for(int k =1; ; k++){
                int points = k*(k+1)/2;

                if(i+points> n) break;

                dp[i+points] = Math.min(
                    dp[i+points], 
                    dp[i]+k +1
                );
            }
        }
        return dp[n];
    }
}