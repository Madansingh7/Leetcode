class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> mp;
        mp[0] =-1;  // Prefix sum 0 before array starts

        int sum =0;
        int ans =0;

        for (int i =0; i <nums.size(); i++){
        // Convert 0 -> -1, 1 -> +1
            if(nums[i] == 0)
                sum--;
            else
                sum++;

            // If this prefix sum has been seen before
            if(mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            }
            // Store only the first occurrence
            else{
                mp[sum] = i;
            }
        }
        return ans;
    }
};