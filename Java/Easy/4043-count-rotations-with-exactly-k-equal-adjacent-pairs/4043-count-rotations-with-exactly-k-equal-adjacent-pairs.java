class Solution {

    public int countRotations(String s, int k) {

        int n = s.length();
        int ans = 0;

        char[] arr = s.toCharArray();

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 1; j < n; j++) {
                if (arr[j] == arr[j - 1]) cnt++;
            }
            if (cnt == k) ans++;
         
            // Rotate left by one position
            char ele = arr[0];
            int j = 0;
            while (j < n - 1) {
                arr[j] = arr[j + 1];
                j++;
            }
            arr[j] = ele;
        }

        return ans;
    }
}