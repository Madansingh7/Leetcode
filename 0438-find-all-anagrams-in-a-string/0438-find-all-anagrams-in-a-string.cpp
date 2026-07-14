class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int m=s.size(), n=p.size();
        vector<int>ans;

        //edge case
        if(n>m){
            return ans;
        }

        vector<int>freq(26,0);
        vector<int>windowFreq(26,0);
        int left=0;

        //first window
        for(int i=0; i<n; i++){
            freq[p[i] - 'a']++;
            windowFreq[s[i] - 'a']++;
        }
        if(freq == windowFreq){
            ans.push_back(left);
        }

        for(int right=n; right<m; right++){
            //add element and increment its frequency
            windowFreq[s[right] - 'a']++;

            //if invalid shrink window
            if((right-left+1) > n){
                windowFreq[s[left] - 'a']--;
                // if(windowFreq[s[left] - 'a'] == 0){
                //     windowFreq.remove(s[left]);
                // }
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