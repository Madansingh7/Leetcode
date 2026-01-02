

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int *res = (int*)malloc(numsSize * sizeof(int));
    
    int i;
    for (i =0; i < n; i++) {
        res[2*i] = nums[i];       
        res[2*i + 1] = nums[i + n]; 
    }

    *returnSize = numsSize;
    return res;
}