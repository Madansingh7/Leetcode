class Solution {
public:
    void reverseString(vector<char>& s) {
        // two pointer approach
        int i=0, j=s.size()-1;
        while(i<j){
            swap(s[i++],s[j--]);
        }
    }
};