import java.util.*;

class Solution {
    public long maxSubarrays(int n, int[][] conflictingPairs) {

        List<List<Integer>> pairs = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            pairs.add(new ArrayList<>());
        }

        // Store the smaller number for each larger number
        for (int[] pair : conflictingPairs) {
            int a = Math.min(pair[0], pair[1]);
            int b = Math.max(pair[0], pair[1]);

            pairs.get(b).add(a);
        }

        long ans = 0;

        // best = largest conflicting left boundary
        int best = 0;

        // secondBest = second largest boundary
        int secondBest = 0;

        // gain[i] = extra subarrays obtained if the
        // conflicting pair responsible for best is removed
        long[] gain = new long[n + 1];

        for (int r = 1; r <= n; r++) {

            for (int a : pairs.get(r)) {

                if (a > best) {
                    secondBest = best;
                    best = a;
                } 
                else if (a > secondBest) {
                    secondBest = a;
                }
            }

            // Without removing anything, valid subarrays
            // ending at r start after 'best'
            ans += r - best;

            // If we remove the pair producing 'best',
            // we can additionally start from secondBest + 1
            gain[best] += best - secondBest;
        }

        long maxGain = 0;

        for (long x : gain) {
            maxGain = Math.max(maxGain, x);
        }

        return ans + maxGain;
    }
}