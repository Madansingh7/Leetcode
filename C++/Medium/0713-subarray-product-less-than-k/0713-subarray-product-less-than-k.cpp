class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k==0 || k==1) return 0;

        int left =0;
        int ans=0, product=1;

        for(int right=0; right<nums.size(); right++){
            product*=nums[right];
            while(product>=k){
                product /= nums[left];
                left++;
            }
            ans += right-left+1;
        }
        return ans;
    }
};