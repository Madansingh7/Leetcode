class Solution {
    public int[][] merge(int[][] intervals) {

        // 1. Sort intervals by starting value
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        // 2. Store the answer
        ArrayList<int[]> result = new ArrayList<>();

        // 3. Add the first interval
        result.add(intervals[0]);

        // 4. Check remaining intervals
        for (int i = 1; i < intervals.length; i++) {

            int[] previous = result.get(result.size() - 1);
            int[] current = intervals[i];

            // 5. If they overlap
            if (current[0] <= previous[1]) {

                previous[1] = Math.max(previous[1], current[1]);

            } 
            // 6. If they don't overlap
            else {
                result.add(current);
            }
        }

        // 7. Convert ArrayList to 2D array
        return result.toArray(new int[result.size()][]);
    }
}