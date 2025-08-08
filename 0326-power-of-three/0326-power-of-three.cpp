class Solution {
public:
    bool isPowerOfThree(int n) {
           if(n<=0)return false;//if 0 or -ve it always not a power of 2
        while(n % 3 == 0){//if its divisible by 3
            n /= 3; //divide by 3 until we get 1
        }
        return n == 1;
    }
};