class Solution {
public:
    int findBeauty(vector<int>& freq, int x) {
        int cnt = 0;

        // Check negatives from smallest (-50) to largest (-1)
        for (int val = -50; val <= -1; val++) {
            cnt += freq[val + 50];

            if (cnt >= x)
                return val;
        }

        return 0;
    }

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        vector<int> freq(50, 0);

        //frequency for the first window
        for (int i = 0; i < k; i++) {
            if (nums[i] < 0)
                freq[nums[i] + 50]++;
        }

        ans.push_back(findBeauty(freq, x));

        // Slide the window
        for (int right = k; right < nums.size(); right++) {
            int left = right - k;

            // Remove outgoing element
            if (nums[left] < 0)
                freq[nums[left] + 50]--;

            // Add incoming element
            if (nums[right] < 0)
                freq[nums[right] + 50]++;

            ans.push_back(findBeauty(freq, x));
        }

        return ans;
    }
};