class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Base case: one way to have prefix sum = 0
        mp[0] = 1;

        int currSum = 0;
        int count = 0;

        for (int num : nums) {
            // Update current prefix sum
            currSum += num;

            // Required previous prefix sum
            int need = currSum - k;

            // If found, add all occurrences
            if (mp.find(need) != mp.end()) {
                count += mp[need];
            }

            // Store current prefix sum
            mp[currSum]++;
        }

        return count;
    }
};