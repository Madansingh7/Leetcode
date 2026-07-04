class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Len = s1.length();
        int s2Len = s2.length();

        if(s1Len > s2Len) return false;

        vector<int>need(26,0);
        vector<int>window(26,0);

        //freq of s1 i.e needed to check permutation
        for(char ch : s1){
            need[ch-'a']++;
        }

        //first window freq plus checking
        for(int i=0; i<s1Len; i++){
            window[s2[i]-'a']++;
        }
        if(need == window){
            return true;
        }

        //check whole s2 starting with second window
        int left = 0;
        for(int right=s1Len; right<s2Len; right++){

            window[s2[left]-'a']--;
            window[s2[right]-'a']++;

            if(need == window) return true;

            left++;
        }
        return false;
    }
};