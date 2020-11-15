class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if (i + 1 < grid.size() && j + 1 < grid[0].size()) {
                    grid[i][j] = min(grid[i + 1][j] + grid[i][j], grid[i][j + 1] + grid[i][j]);
                    continue;
                }
                if (i + 1 < grid.size()) {
                    grid[i][j] += grid[i + 1][j];
                    continue;
                }
                if (j + 1 < grid[0].size()) {
                    grid[i][j] += grid[i][j + 1];
                    continue;
                }
            }
        }
        return grid[0][0];
    }
};
