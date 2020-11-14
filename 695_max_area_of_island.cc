class Solution {
public:
    int helper(vector<vector<int>>& grid, vector<vector<bool>>& dp, int i, int j) {
        if (i >= grid.size() || i < 0 || j >= grid[i].size() || j < 0)
            return 0;
        if (grid[i][j] == 0 || dp[i][j] == true)
            return 0;
        dp[i][j] = true;
        return helper(grid, dp, i + 1, j) + 
               helper(grid, dp, i, j - 1) + 
               helper(grid, dp, i - 1, j) + 
               helper(grid, dp, i, j + 1) + 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int out = 0;
        vector<vector<bool>> dp(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                out = max(helper(grid, dp, i, j), out);
            }
        }
        return out;
    }
};
