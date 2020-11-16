class Solution {
public:
    void helper(vector<vector<int>>& grid, int i, int j, int flag) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if (flag == -1)
            return;
        if (grid[i][j] == -1)
            return;
        if (grid[i][j] != flag)
            return;
        grid[i][j] = -1;
        helper(grid, i, j - 1, flag);
        helper(grid, i - 1, j, flag);
        helper(grid, i, j + 1, flag);
        helper(grid, i + 1, j, flag);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size() + grid[0].size() - 1; i++) {
            if (i / grid.size() < 1) {
                helper(grid, i, 0, grid[i][0]);
            } else {
                int u = grid.size() - 1;
                int v = i - grid.size() + 1;
                helper(grid, u, v, grid[u][v]);
            }
            if (i / grid[0].size() < 1) {
                helper(grid, 0, i, grid[0][i]);
            } else {
                int u = i - grid[0].size() + 1;
                int v = grid[0].size() - 1;
                helper(grid, u, v, grid[u][v]);
            }
        }
        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid[0].size() - 1; j++) {
                if (grid[i][j] == 0) {
                    helper(grid, i, j, 0);
                    count++;
                }
            }
        }
        return count;
    }
};
