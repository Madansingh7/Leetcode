class Solution {
public:
    bool isValid(vector<int>& nums, int k, int maxAllowedPages) {
    int stu=1, pages=0;

    for(int i=0; i<nums.size(); i++){
        if(nums[i]>maxAllowedPages)return false;
        if(pages+nums[i] <= maxAllowedPages){
            pages+=nums[i];
        }
        else{
            stu++;
            pages=nums[i];
        }
    }
    return stu > k ? false : true;
    }
    int splitArray(vector<int>& nums, int k) {
        int st = 0, end = accumulate(nums.begin(), nums.end(), 0);//0 is initial value
        int ans=-1;

        if(k>nums.size()){
            return -1;
        }
        while(st<=end){
            int mid = st + (end - st) / 2;

            if(isValid(nums, k, mid)){//valid than solution is on left
                ans=mid;
                end=mid-1;
            }
            else{//valid than solution is on right
                st=mid+1;
            }
        }
    return ans;
    }
};