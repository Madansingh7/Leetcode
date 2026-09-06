class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //edge cases
        if(k==0 || k==1) return 0;

        int left =0, product=1, count=0;

        //slinding window logicc
        for(int right=0; right<nums.size(); right++){
            product*=nums[right];

            //if not satisfy condition shrink window else this part not execute and right go on increase
            while(product>=k){
                product/=nums[left];
                left++;
            }
            //count every windows no of sub arrays
            count+=right-left+1;
        }
        return count;
    }
};