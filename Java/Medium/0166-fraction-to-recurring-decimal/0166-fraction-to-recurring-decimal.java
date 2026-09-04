class Solution {
    public String fractionToDecimal(int num, int den) {

        StringBuilder ans = new StringBuilder();

        long numerator = num;
        long denominator = den;

        if (numerator == 0) {
            return "0";
        }

        // Handle negative result
        if ((numerator < 0) ^ (denominator < 0)) {
            ans.append("-");
        }

        numerator = Math.abs(numerator);
        denominator = Math.abs(denominator);

        long q = numerator / denominator;
        long r = numerator % denominator;

        ans.append(q);

        if (r == 0) {
            return ans.toString();
        }

        ans.append(".");

        HashMap<Long, Integer> map = new HashMap<>();

        while (r != 0) {

            if (map.containsKey(r)) {
                int index = map.get(r);
                ans.insert(index, "(");
                ans.append(")");
                break;
            }

            map.put(r, ans.length());

            r *= 10;
            q = r / denominator;
            r = r % denominator;

            ans.append(q);
        }

        return ans.toString();
    }
}