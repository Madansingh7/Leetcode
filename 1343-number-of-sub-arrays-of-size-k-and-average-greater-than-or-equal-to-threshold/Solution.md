# leetcode - 1343 | Runtime 100% beats | Memory 97.35% beats


# Approach
<!-- Describe your approach to solving the problem. -->
- because its fixed every time with k size, that means its clearly  **SLIDING WINDOW** with **K size**
- Now calculate first window sum till k 
- after check first window start right with k and left with 0 
- if condition i.e  **sum\k >= threshold or sum >=  k * threshold** if this satisfy then take a count increament that it is valid subarray
- if condition fails then move window left++ and right++
   
# Complexity
- Time complexity: **O(N)**
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: **O(1)**
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
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
```