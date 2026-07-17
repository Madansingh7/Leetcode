class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        mp[0]=1;

        int curSum=0, count=0;

        for(int i=0; i<nums.size(); i++){
            curSum+=nums[i];
            int need = curSum-k;

            if(mp.find(need) != mp.end()){
                count+=mp[need];
            }

            mp[curSum]++;
        }

        return count;
    }
};