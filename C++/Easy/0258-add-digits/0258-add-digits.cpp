class Solution {
public:
    int addDigits(int num) {
        if(num<10)return num;
        int sum=0;
        label:
        while(num>0){
         sum+=(num%10);
         num=num/10;       
        }
        if(sum>9){
            num=sum;
            sum=0;
            goto label;
        }

        return sum;
    }
};