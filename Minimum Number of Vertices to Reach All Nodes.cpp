// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        04 Dec 2021
//  @Detail  :        Minimum Number of Vertices to Reach All Nodes (LeetCode)
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
    
    void toposort(int node, stack<int> &topo, vector<bool> &vis, vector<vector<int>> &graph)
    {
        vis[node] = true;
        
        for(int &x : graph[node])
        {
            if(vis[x] == true)
                continue;
            toposort(x, topo, vis, graph);
        }
        topo.push(node);
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
      
        for(vector<int> &x : edges)
            graph[x[0]].push_back(x[1]);
        
        stack<int> topo;
        vector<bool> vis(n, false);
        
        for(int i = 0; i < n; i++)
            if(!vis[i])
                toposort(i, topo, vis, graph);
        
        fill(vis.begin(), vis.end(), false);
        vector<int> result;
        
        while(!topo.empty())
        {
            int node = topo.top();    topo.pop();
            if(vis[node] == true)
                continue;
            result.push_back(node);
            dfs(node, vis, graph);
        }
        return result;
    }
};
