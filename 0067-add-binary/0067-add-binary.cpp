class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.size() - 1;   // pointer for str a at last
        int j = b.size() - 1;   // pointer for str b at last
        int carry = 0;

        string ans = "";

        while(i >= 0 || j >= 0 || carry) {

            int sum = carry;

            // take digit from a
            if(i >= 0){
                sum += a[i] - '0';   // convert char to int
                i--;
            }

            // take digit from b
            if(j >= 0){
                sum += b[j] - '0';
                j--;
            }

            // current bit
            ans += (sum % 2) + '0';

            // update carry
            carry = sum / 2;
        }

        // answer is reversed
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
