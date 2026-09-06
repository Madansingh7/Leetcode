int peakIndexInMountainArray(int* arr, int arrSize) {
      int st=1, end=arrSize-2;//because to avoid unnecessary
        while(st<=end){
            int mid = st + (end-st) /2;
            if(arr[mid-1] < arr[mid] && arr[mid]> arr[mid+1]){
                return mid;   
            } 
           else if(arr[mid-1] < arr[mid]){//increasing then peak lies on right side
                st=mid+1;
            }
            else{ //deacreasing then peak lies on left side
                end=mid-1;
            }
        }
        return -1;
}