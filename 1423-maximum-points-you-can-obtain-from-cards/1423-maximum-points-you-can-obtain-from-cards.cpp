class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
    
        int sum = 0;
        int left = k - 1;
        int right = cardPoints.size() - 1;
        int ans;

        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        ans = sum;
        while (left >= 0) {
            sum -= cardPoints[left];
            left--;
            sum += cardPoints[right];
            right--;

            ans = max(ans, sum);
        }
        return ans;
    }
};