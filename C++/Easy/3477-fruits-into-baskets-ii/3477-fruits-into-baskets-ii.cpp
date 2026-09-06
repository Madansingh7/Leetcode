class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count=0, n=fruits.size();
        for(int val : fruits){
            for(int i=0; i<baskets.size(); i++){
                if(baskets[i] >= val){
                    baskets[i]=-1;
                    count++;
                    break;
                }
            }
        }
        return n-count;
    }
};