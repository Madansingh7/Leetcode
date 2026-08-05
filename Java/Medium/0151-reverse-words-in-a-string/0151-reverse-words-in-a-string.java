class Solution {
    public String reverseWords(String s) {
      
        String ans = "";

        // Reverse the entire string      
        s = new StringBuilder(s).reverse().toString();

        for (int i = 0; i < s.length(); i++) {
            String word = "";
                               
            while (i < s.length() && s.charAt(i) != ' ') {
                word += s.charAt(i);
                i++;
            }

            // Reverse the current word
            word = new StringBuilder(word).reverse().toString();
     
            if (word.length() > 0) {
                ans += " " + word;
            }
        }

        // Remove the leading space
        return ans.substring(1);
    }
}