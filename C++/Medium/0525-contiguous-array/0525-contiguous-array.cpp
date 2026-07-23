class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> mp;
        int curSum = 0;
        mp[0] = -1; // Prefix sum 0 before array starts and index is -1

        int ans=0;

        for (int i = 0; i < nums.size(); i++) {
            curSum += (nums[i]==1)? 1 : -1;

            // If this prefix sum has been seen before
            if (mp.find(curSum) != mp.end()) {
                ans = max(ans, i - mp[curSum]);
            }
            // if not store only the first occurrence
            else {
                mp[curSum] = i;
            }
        }
        return ans;
    }
};