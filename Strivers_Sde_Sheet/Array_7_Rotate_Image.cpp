// Solution 1  ---> T.C{O(n*n)} S.C{O(n*n)}
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = matrix[n- j- 1][i];
            }
        }
        matrix = ans;

        
    }
};

//Solution 2 Optimum
// T.C{O(n*n)} S.C{O(1)}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        //transposing the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reversing each row of the matrix
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        
    }
};
