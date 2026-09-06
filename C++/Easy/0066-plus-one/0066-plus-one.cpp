class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;   // just add 1 and done
                return digits; // no carry, return immediately
            }
            digits[i] = 0; // if digit was 9, it becomes 0, carry continues
        }
        
        // If we reach here, it means all digits were 9
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};
