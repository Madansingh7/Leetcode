class Solution {
public:
    bool hasAllCodes(string s, int k) {

        unordered_set<string> freq;
        if (k > s.length())
            return false;

        for (int i = 0; i <= s.length() - k; i++) {
            string str = s.substr(i, k);
            freq.insert(str);

            // Early exit if all codes are found
            if (freq.size() == (1 << k))
                return true;
        }

        return false;
    }
};
//we can use pow(n,k) but it returns double so for simplicity 
//use 1<<k