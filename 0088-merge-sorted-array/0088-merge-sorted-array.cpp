class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         int i=m-1, j=n-1, index=m+n-1;
    while(i>=0&&j>=0){
        // if nums1 is greater
        if(nums1[i]>=nums2[j]){
            nums1[index]=nums1[i];
            i--;
            index--;
        }
        //if nums2 is greater 
        else{
            nums1[index]=nums2[j];
            index--;
            j--;
        }
    }
    // if all nums1 elements are higher then nums2 then nums2 remains as it is then just copy it too nums1
    while(j>=0){
        nums1[index--]=nums2[j--];
    }
    }
};