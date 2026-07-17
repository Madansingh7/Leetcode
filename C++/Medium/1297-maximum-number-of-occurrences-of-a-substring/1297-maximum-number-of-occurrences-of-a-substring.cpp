class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> subFreq;
        unordered_map<char, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;

            // Keep window size <= minSize
            if (right - left + 1 > minSize) {
                freq[s[left]]--;

                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                left++;
            }

            // Window size == minSize
            if (right - left + 1 == minSize) {

                // Check distinct characters
                if (freq.size() <= maxLetters) {
                    string sub = s.substr(left, minSize);

                    subFreq[sub]++;

                    ans = max(ans, subFreq[sub]);
                }
            }
        }

        return ans;
    }
};