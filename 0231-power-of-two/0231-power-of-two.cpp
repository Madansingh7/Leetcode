class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;//if 0 or -ve it always not a power of 2
        while(n % 2 == 0){//if its even
            n /= 2; //divide by 2 until we get 1
        }
        return n == 1 ? true : false;
    }
};