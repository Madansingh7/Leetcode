class Solution {
    public int countGoodRotations(int[] nums) {

        int n = nums.length;
        int half = n / 2;

        long total = 0;

        for (int x : nums)  total += x;
        
        // First window
        long window = 0;

        for (int i = 0; i < half; i++) {
            window += nums[i];
        }

        int ans = 0;

        // Process first window
        if (window * 2 > total) ans++;

        // Slide the window
        for (int left = 0; left < n - 1; left++) {
            int right = (left + half) % n;

            window -= nums[left];
            window += nums[right];

            if (window* 2 > total) ans++;
        }

        return ans;
    }
}