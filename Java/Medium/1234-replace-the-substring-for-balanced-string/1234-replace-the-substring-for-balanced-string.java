class Solution {
    public int balancedString(String s) {
        int n = s.length();
        int need = n / 4;

        int[] cnt = new int[128];

        for (char c : s.toCharArray()) {
            cnt[c]++;
        }

        // Already balanced
        if (cnt['Q'] == need &&
            cnt['W'] == need &&
            cnt['E'] == need &&
            cnt['R'] == need) {
            return 0;
        }

        int left = 0;
        int ans = n;

        for (int right = 0; right < n; right++) {

            cnt[s.charAt(right)]--;

            while (left <= right &&
                   cnt['Q'] <= need &&
                   cnt['W'] <= need &&
                   cnt['E'] <= need &&
                   cnt['R'] <= need) {

                ans = Math.min(ans, right - left + 1);

                cnt[s.charAt(left)]++;
                left++;
            }
        }

        return ans;
    }
}