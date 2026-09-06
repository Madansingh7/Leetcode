class Solution {
    public int reverseBits(int n) {
        int ans = 0;

        for(int i = 0; i < 32; i++){

            ans = ans << 1;        // make space
            ans = ans | (n & 1);   // add last bit
            n = n >> 1;            // remove last bit
        }

        return ans;
    }
}