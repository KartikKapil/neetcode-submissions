class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int r, int c, vector<vector<int>> &vis) {
        if(i<0||j<0||i>=r||j>=c || vis[i][j]==1 || grid[i][j]=='0') {
            return;
        }
        vis[i][j] = 1;
        dfs(grid, i+1, j, r, c, vis);
        dfs(grid, i-1, j, r, c, vis);
        dfs(grid, i, j+1, r, c, vis);
        dfs(grid, i, j-1, r, c, vis);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int totalIsland = 0;
        vector<vector<int>> vis(r, vector<int>(c,0));
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(grid[i][j]=='1' && vis[i][j]==0) {
                    totalIsland++;
                    dfs(grid, i, j, r, c, vis);
                }
            }
        }
        return totalIsland;
    }
};