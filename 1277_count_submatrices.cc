class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int sum = 0;
        vector<vector<int>> count{matrix.size() + 1, vector<int>(matrix[0].size() + 1)};
        for (int i = 1; i < matrix.size() + 1; i++) {
            for (int j = 1; j < matrix[0].size() + 1; j++) {
                if (matrix[i - 1][j - 1] == 1) {
                    count[i][j] = 1 + min(count[i - 1][j - 1], min(count[i - 1][j], count[i][j - 1]));
                    sum += count[i][j];
                }
            }
        }
        return sum;
    }
};
