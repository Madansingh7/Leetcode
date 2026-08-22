class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {

        List<List<Integer>> ans = new ArrayList<>();

        Arrays.sort(nums);
        for(int i =0; i <nums.length - 3; i++){

            //skip duplicates of i
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            for(int j = i + 1; j < nums.length - 2; j++){

                //skip duplicates of j
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }

                int left = j + 1;
                int right = nums.length -1;

                while(left < right){

                    long sum = (long) nums[i]+ nums[j]+ nums[left]+ nums[right];
                             
                    if (sum == target) {

                        ans.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                            
                        //skip duplicates of left values
                        while(left < right && nums[left] == nums[left + 1]){
                            left++;
                        }

                        //skip duplicates of right values
                        while(left < right && nums[right] == nums[right - 1]){
                            right--;
                        }

                        left++;
                        right--;
                    }
                    else if(sum < target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        return ans;
    }
}