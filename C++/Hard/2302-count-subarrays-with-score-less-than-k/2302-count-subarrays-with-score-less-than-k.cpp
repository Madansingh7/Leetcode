class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        int left = 0;
        long long sum = 0;
        long long ans = 0;

        for(int right = 0; right < nums.size(); right++){

            //expand the window
            sum += nums[right];

            //shrink until score becomes valid
            while(sum * (right - left + 1) >= k){
                sum -= nums[left];
                left++;
            }

            //all subarrays ending at 'right' are valid
            ans += (right - left + 1);
        }

        return ans;
    }
};