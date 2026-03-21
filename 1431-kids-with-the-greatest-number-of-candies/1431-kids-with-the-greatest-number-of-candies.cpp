class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // used max_element stl to find max candies
        auto max = max_element(candies.begin(),candies.end());
        // it returns iterator 

        vector<bool>res;

        // for(int i=0; i<candies.size(); i++){
        //     if(candies[i]+ extraCandies >= *max){
        //         res.push_back(true);
        //     }
        //     else{
        //         res.push_back(false);
        //     }
        // }

        // this uses for each loop reduces the code
         for(int c : candies ){
            res.push_back(c + extraCandies >= *max);
        }
        return res;
    }
};