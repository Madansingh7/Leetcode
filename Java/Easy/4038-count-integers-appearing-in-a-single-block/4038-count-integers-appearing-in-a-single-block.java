class Solution {
    public int countSpecialIntegers(int[] nums) {

        int cnt = 0;

        for (int i = 0; i < nums.length; i++) {

            int current = nums[i];

            // Skip if this number was already processed
            boolean already = false;

            for (int k = 0; k < i; k++) {
                if (nums[k] == current) {
                    already = true;
                    break;
                }
            }

            if (already) {
                continue;
            }

            // Move through current block
            int j = i;

            while (j + 1 < nums.length && nums[j + 1] == current) {
                j++;
            }

            // Check if current appears after its block
            boolean found = false;

            for (int k = j + 1; k < nums.length; k++) {
                if (nums[k] == current) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                cnt++;
            }

            i = j;
        }

        return cnt;
    }
}