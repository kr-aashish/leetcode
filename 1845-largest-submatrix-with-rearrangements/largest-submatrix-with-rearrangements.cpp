class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix.back().size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i and matrix[i][j]) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            sort(matrix[i].rbegin(), matrix[i].rend());
        }

        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans = max(ans, (j + 1) * matrix[i][j]);
            }
        }

        return ans;
    }
};