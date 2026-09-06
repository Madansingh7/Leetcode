class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;

        int k = words[0].size(), n = words.size();
        unordered_map<string,int> freq;

        //freq stores frequency of words used to reset curr freqency
        for(auto &w : words) freq[w]++;

        for(int i = 0; i < k; i++) {
            unordered_map<string,int> curr;
            int left = i, cnt =0;

            for(int right = i; right + k <= s.size(); right += k) {
                string w = s.substr(right, k);

                if (!freq.count(w)) {
                    curr.clear();
                    cnt = 0;
                    left = right + k;
                    continue;
                }

                curr[w]++, cnt++;

                while (curr[w] > freq[w]) {
                    string t = s.substr(left, k);
                    curr[t]--;
                    left += k;
                    cnt--;
                }

                if (cnt == n) {
                    ans.push_back(left);
                    string t = s.substr(left, k);
                    curr[t]--;
                    left += k;
                    cnt--;
                }
            }
        }
        return ans;
    }
};