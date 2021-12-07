// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        07 Dec 2021
//  @Detail  :        Course Schedule II (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
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
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        
        for(vector<int> &x : prerequisites)
            graph[x[1]].push_back(x[0]);
        
        vector<bool> vis(n, false), dfsVis(n, false);
        
        for(int i = 0; i < n; i++)
            if(!vis[i] && cycle(i, vis, dfsVis, graph))
                return {};
        
        stack<int> topo;
        fill(vis.begin(), vis.end(), false);
        
        for(int i = 0; i < n; i++)
            if(!vis[i])
                toposort(i, topo, vis, graph);
        
        vector<int> result;
        while(!topo.empty())
        {
            int node = topo.top();    topo.pop();
            result.push_back(node);
        }
        return result;
    }
};
