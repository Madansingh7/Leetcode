class Solution {
    public String addBinary(String a, String b) {

        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        StringBuilder ans = new StringBuilder();

        while (i >= 0 || j >= 0 || carry == 1) {

            int sum = carry;

            // take digit from a
            if (i >= 0) {
                sum += a.charAt(i) - '0';
                i--;
            }

            // take digit from b
            if (j >= 0) {
                sum += b.charAt(j) - '0';
                j--;
            }

            // result bit
            ans.append(sum % 2);

            // new carry
            carry = sum / 2;
        }

        // reverse because we built from right → left
        return ans.reverse().toString();
    }
}
