class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {

        if (k==0 || k==1) return 0;

        int n=nums.length;
        int left=0;
        int ans =0;
        int product =1;
        for(int right=0; right<n; right++){
            product *= nums[right];

            while(product >= k){
                product /= nums[left];
                left++;
            }
            ans += right-left+1;
        }
        return ans;
    }
}