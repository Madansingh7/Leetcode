class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int minElement = *min_element(nums.begin(), nums.end());

        return gcd(minElement, maxElement);
    }
};