// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        07 Dec 2021
//  @Detail  :        Course Schedule (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool cycle(int node, vector<bool> &vis, vector<bool> dfsVis, vector<vector<int>> &graph)
    {
        vis[node] = true;
        dfsVis[node] = true;
        
        for(int &x : graph[node])
        {
            if(!vis[x])
            {
                if(cycle(x, vis, dfsVis, graph))
                    return true;
            }
            else if(dfsVis[x] == true)
                    return true;
        }
        
        dfsVis[node] = false;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        
        for(vector<int> &x : prerequisites)
            graph[x[1]].push_back(x[0]);
        
        vector<bool> vis(n, false), dfsVis(n, false);
        
        for(int i = 0; i < n; i++)
            if(!vis[i] && cycle(i, vis, dfsVis, graph))
                return false;
        return true;
    }
};
