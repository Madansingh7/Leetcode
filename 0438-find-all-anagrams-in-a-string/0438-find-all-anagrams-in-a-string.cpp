class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int m=s.size(), n=p.size();
        vector<int>ans;
        if(n>m){
            return ans;
        }

        unordered_map<char, int>freq;
        unordered_map<char, int>windowFreq;
        int left=0;

        for(int i=0; i<n; i++){
            freq[p[i]]++;
            windowFreq[s[i]]++;
        }
        if(freq == windowFreq){
            ans.push_back(left);
        }

        for(int right=n; right<m; right++){
            //add element and increment its frequency
            windowFreq[s[right]]++;

            //if invalid shrink window
            while((right-left+1) > n){
                windowFreq[s[left]]--;
                if(windowFreq[s[left]] == 0){
                    windowFreq.erase(s[left]);
                }
                left++;
            }

            //check if freq of p is equal to windowFreq 
            if(freq == windowFreq){
                ans.push_back(left);
            }
        }
        return ans;
    }
};