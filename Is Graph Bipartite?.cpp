// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        04 Dec 2021
//  @Detail  :        Is Graph Bipartite? (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool dfs(int node, int color, vector<int> &vis, vector<vector<int>> &graph)
    {
        vis[node] = color;
        
        for(int &x : graph[node])
        {
            if(vis[x] == -1)
            {
                if(!dfs(x, !color, vis, graph))
                    return false;
            }
            else if(vis[x] == color)
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        
        for(int i = 0; i < n; i++)
            if(vis[i] == -1)
                if(!dfs(i, 0, vis, graph))
                    return false;
        return true;
    }
};
