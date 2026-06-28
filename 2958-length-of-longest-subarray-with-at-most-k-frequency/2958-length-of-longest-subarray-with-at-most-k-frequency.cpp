class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left =0; 
        int ans =0;

        //to store frequency
        unordered_map<int, int>freq;

        for(int right=0; right<nums.size(); right++){
            freq[nums[right]]++;
            while(freq[nums[right]]>k){
                freq[nums[left]]--;

                //if frequency of element is zero than no use of storing it so remove it
                // if(freq[nums[left]]==0){
                //     freq.erase(nums[left]);
                // }

                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};