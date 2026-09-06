class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0, n=s.size(); 
        int count =0;
        unordered_map<char, int>freq;

        for (int right = 0; right <n; right++){
            freq[s[right]]++;

            while (freq['a'] > 0 &&freq['b'] > 0 &&freq['c'] > 0){
                count += (n - right);

                freq[s[left]]--;
                left++;
            }   
        }
        return count;
    }
};