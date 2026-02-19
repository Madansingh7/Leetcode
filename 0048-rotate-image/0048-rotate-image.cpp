class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        //Take transpose i.e [i][j] --> [j][i]
        for(int i=0; i<n; i++){
            //why from i+1 bcz diagonal part is untouched it remains same after transpose
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //reverse all rows only
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};