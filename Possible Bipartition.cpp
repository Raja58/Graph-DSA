// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        04 Dec 2021
//  @Detail  :        Possible Bipartition (LeetCode)
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
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        vector<int> vis(n + 1, -1);
        
        for(vector<int> &x : dislikes)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        for(int i = 1; i <= n; i++)
            if(vis[i] == -1)
                if(!dfs(i, 0, vis, graph))
                    return false;
        return true;
    }
};
