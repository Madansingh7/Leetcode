class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach=0;
        for(int i=0; i<nums.size(); i++){
            if(i>maxReach){
                return false;
                //we cannot reach end index
            }
            maxReach=max(maxReach, i+nums[i]);
        }
        // it can reach to end 
        return true;
    }
};