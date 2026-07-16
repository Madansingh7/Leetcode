class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left=0;
        int sum=0, ans=0;

        for(int right=0; right<s.length(); right++){
            sum += abs(s[right]-t[right]);
            while(sum>maxCost){
                sum -= abs(s[left]-t[left]);
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};