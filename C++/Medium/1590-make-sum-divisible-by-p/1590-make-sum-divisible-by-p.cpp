class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;

        for (int num : nums)
            totalSum += num;

        int target = totalSum % p;

        // Already divisible
        if (target == 0)
            return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;  // Prefix remainder 0 before array starts

        long long prefixSum = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int currRem = prefixSum % p;

            // We need a previous remainder so that
            // (currRem - prevRem + p) % p == target
            int needed = (currRem - target + p) % p;

            if (mp.count(needed)) {
                ans = min(ans, i - mp[needed]);
            }

            // Store latest index for this remainder
            mp[currRem] = i;
        }

        return (ans == nums.size()) ? -1 : ans;
    }
};