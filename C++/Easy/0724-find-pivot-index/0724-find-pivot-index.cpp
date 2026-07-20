class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>prefix(n);

        prefix[0]=nums[0];
        for(int i=1; i<n; i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        
        int totalSum=prefix[n-1];

        for(int i=0; i<n; i++){
            int leftSum=(i==0)?0:prefix[i-1];
            int rightSum=totalSum-prefix[i];

            if(leftSum == rightSum){
                return i;
            }
        }
        return -1;
    }
};