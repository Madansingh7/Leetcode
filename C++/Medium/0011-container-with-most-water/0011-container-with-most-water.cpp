class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int lp=0, rp=n-1,width, hgt,currWater ,maxWater=0;
        while(lp<rp){
            width = rp-lp;
            hgt = min(height[lp],height[rp]);
            currWater = width*hgt;
            maxWater = max(maxWater, currWater);

            height[lp]<height[rp] ? lp++ : rp--;
        
        }
        return maxWater;
    }
};