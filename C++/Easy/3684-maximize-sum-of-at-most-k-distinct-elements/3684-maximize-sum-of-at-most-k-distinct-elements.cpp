class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++)
        {
         if(i==0 || nums[i] != nums[i-1])
         ans.push_back(nums[i]);
         if(ans.size()==k)
         break;
        }
        
    
    return ans;  
    }
};