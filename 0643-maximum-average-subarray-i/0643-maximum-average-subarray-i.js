/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findMaxAverage = function(nums, k) {
    
    let n=nums.length;
   
    let sum=0;
    for(let i=0; i<k; i++){
        sum+=nums[i];
    }
    let maxAvg=sum/k;

    let i=0, j=k;
    while(j<n){
        sum+=nums[j]-nums[i];
        i++;
        j++;
        maxAvg = Math.max(maxAvg, sum/k);
    }
    return maxAvg;
};