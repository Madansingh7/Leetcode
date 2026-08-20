class Solution {
    public int maxSideLength(int[][] mat, int threshold) {

        int rows =mat.length;
        int cols =mat[0].length;

        // 1. Create prefix sum
        int[][] prefix = new int[rows + 1][cols + 1];

        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {

                prefix[i][j] =
                    mat[i - 1][j - 1]
                    + prefix[i - 1][j]
                    + prefix[i][j - 1]
                    - prefix[i - 1][j - 1];
            }
        }

        int answer = 0;

        // 2. Try every possible square size
        for (int size = 1; size <= Math.min(rows, cols); size++) {

            for (int i = size; i <= rows; i++) {
                for (int j = size; j <= cols; j++) {

                    // Find square sum
                    int sum =
                        prefix[i][j]
                        - prefix[i - size][j]
                        - prefix[i][j - size]
                        + prefix[i - size][j - size];

                    if (sum <= threshold) {
                        answer = size;
                    }
                }
            }
        }

        return answer;
    }
}