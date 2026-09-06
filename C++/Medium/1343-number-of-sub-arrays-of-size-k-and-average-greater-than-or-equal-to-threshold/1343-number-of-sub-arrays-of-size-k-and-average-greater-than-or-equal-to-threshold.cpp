class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int left =0; 
        int cnt =0, sum=0;

        for(int i=0; i<k; i++){
            sum += arr[i];
        }

        for(int right=k; right<arr.size(); right++){
            if(sum >= k*threshold){
                cnt++;
            }
            sum -= arr[left];
            left++;
            sum += arr[right];
        }
        if(sum >= k*threshold){
                cnt++;
        }
        return cnt;
    }
};