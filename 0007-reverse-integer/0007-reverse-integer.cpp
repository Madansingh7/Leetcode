class Solution {
public:
    int reverse(int x) {

        long long rev=0;//took long long to avoid overflow

        while(x!=0){
            int num = x%10;
            rev=(rev*10) + num;
            x/=10;
        }

        if(rev<INT_MIN || rev>INT_MAX) return 0;//checking for overflow

        return (int)rev;
    }
};