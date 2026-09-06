class Solution {

    public int countRotations(String s, int k) {

        int n = s.length();

        int equal = 0;

        // Count equal adjacent pairs in the circle
        for (int i = 0; i < n; i++) {

            if (s.charAt(i) == s.charAt((i + 1) % n)) {
                equal++;
            }
        }

        int unequal = n - equal;

        if (k == equal) {
            return unequal;
        }

        if (k == equal - 1) {
            return equal;
        }

        return 0;
    }
}
