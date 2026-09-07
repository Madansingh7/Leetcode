class Solution {
    public double findMedianSortedArrays(int[] a, int[] b) {

        if (a.length > b.length)
            return findMedianSortedArrays(b, a);

        int m = a.length;
        int n = b.length;

        int low = 0, high = m;

        while (low <= high) {

            int cutA = (low + high) / 2;
            int cutB = (m + n + 1) / 2 - cutA;

            int leftA = cutA == 0 ? Integer.MIN_VALUE : a[cutA - 1];
            int rightA = cutA == m ? Integer.MAX_VALUE : a[cutA];

            int leftB = cutB == 0 ? Integer.MIN_VALUE : b[cutB - 1];
            int rightB = cutB == n ? Integer.MAX_VALUE : b[cutB];

            if (leftA <= rightB && leftB <= rightA) {

                if ((m + n) % 2 == 1)
                    return Math.max(leftA, leftB);

                return (Math.max(leftA, leftB)
                        + Math.min(rightA, rightB)) / 2.0;
            }

            if (leftA > rightB)
                high = cutA - 1;
            else
                low = cutA + 1;
        }

        return 0;
    }
}