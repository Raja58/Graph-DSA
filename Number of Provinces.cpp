// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        04 Dec 2021
//  @Detail  :        Number of Provinces (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &graph)
    {
        vis[node] = true;
        
        for(int &x : graph[node])
        {
            if(vis[x] == true)
                continue;
            dfs(x, vis, graph);
        }
    }
    
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j && grid[i][j] == 1)
                    graph[i].push_back(j);
        
        vector<bool> vis(n, false);
        int result = 0;
        for(int i = 0; i < n; i++)
            if(!vis[i])
            {
                dfs(i, vis, graph);
                result++;
            }
        return result;
    }
};
