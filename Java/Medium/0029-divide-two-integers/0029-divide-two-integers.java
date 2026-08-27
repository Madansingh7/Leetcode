class Solution {
    public int divide(int dividend, int divisor) {

        //Overflow case
        // -infinity/-1 -> + infinity 
        // which reduces iterations 
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        // Determining the sign
        boolean negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long to avoid overflow
        long a = Math.abs((long) dividend);
        long b = Math.abs((long) divisor);

        long answer = 0;

        while (a >= b) {

            long temp = b;
            long count = 1;

            // Keep doubling divisor i.e left shift by multiplying with 2
            while (a >= (temp << 1)) {
                temp = temp << 1;
                count = count << 1;
            }

            // Subtract largest possible chunk from dividend
            a = a - temp;
            answer = answer + count;
        }

        // Apply sign
        if (negative) {
            answer = -answer;
        }

        return (int) answer;
    }
}