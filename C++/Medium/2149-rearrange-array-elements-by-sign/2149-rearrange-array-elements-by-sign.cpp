class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> Pvec,Nvec,res;
       
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<0){
                Nvec.push_back(nums[i]);
            }
            else{
                Pvec.push_back(nums[i]);
            }
        }
        for(int i = 0; i<Pvec.size(); i++){
            res.push_back(Pvec[i]);
            res.push_back(Nvec[i]);
        }
        return res;
    }
};