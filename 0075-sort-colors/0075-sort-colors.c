void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void sortColors(int* nums, int numsSize) {
    int mid=0, low=0, high=numsSize-1;

    while(mid<=high){
        if(nums[mid]==0){
            swap(&nums[low],&nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
                mid++;
        }
        else{
            swap(&nums[high],&nums[mid]);
            high--;
        }
    }
}