class Solution {
public:
    void sortColors(vector<int>& nums) {
        // using DUTCH NATIONAL FAG ALGORITHM
        int mid=0, high=nums.size()-1, low=0;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};