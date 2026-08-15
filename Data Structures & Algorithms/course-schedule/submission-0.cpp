class Solution {
private:
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(int nei : adj[node]) {
            if(vis[nei] == 0) {
                if(dfs(nei, adj, vis, pathVis))
                    return true;
            }
            else if(pathVis[nei] == 1) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(vis[i] == 0) {
                if(dfs(i, adj, vis, pathVis))
                    return false;  // cycle found
            }
        }

        return true;  // no cycle
    }
};