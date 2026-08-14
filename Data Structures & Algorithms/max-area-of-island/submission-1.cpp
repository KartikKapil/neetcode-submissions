class Solution {
public:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j, int row, int col, int &area) {
        if(i<0||j<0||i>=row||j>=col||vis[i][j]==1||grid[i][j]==0) return;
        vis[i][j] = 1;
        area++;
        dfs(grid, vis, i, j-1, row, col,area);
        dfs(grid, vis, i-1, j, row, col,area);
        dfs(grid, vis, i, j+1, row, col,area);
        dfs(grid, vis, i+1, j, row, col,area);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxArea = 0;
        vector<vector<int>> vis(row, vector<int>(col,0));
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j]==1 && vis[i][j]==0) {
                    int area = 0;
                    dfs(grid, vis, i, j, row, col, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
