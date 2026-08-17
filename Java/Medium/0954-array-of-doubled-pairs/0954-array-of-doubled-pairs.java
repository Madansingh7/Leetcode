class Solution {
    public boolean canReorderDoubled(int[] arr) {

        // Frequency of each number
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int x : arr) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }

        // Convert int[] to Integer[] for custom sorting
        Integer[] nums = new Integer[arr.length];

        for (int i = 0; i < arr.length; i++) {
            nums[i] = arr[i];
        }

        // Sort by absolute value
        Arrays.sort(nums, (a, b) ->
            Integer.compare(Math.abs(a), Math.abs(b))
        );

        // Form pairs: (x, 2*x)
        for (int x : nums) {

            // Already completely used
            if (map.get(x) == 0) {
                continue;
            }

            int doubleValue = 2 * x;

            // Required pair doesn't exist
            if (map.getOrDefault(doubleValue, 0) == 0) {
                return false;
            }

            // Consume x
            map.put(x, map.get(x) - 1);

            // Consume 2*x
            map.put(doubleValue, map.get(doubleValue) - 1);
        }

        return true;
    }
}