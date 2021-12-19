// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        19 Dec 2021
//  @Detail  :        Alien Dictionary (LeetCode)
//  ============================
//  -->

class Solution {
public:
    void toposort(int node, vector<bool> &vis, stack<int> &topo, vector<vector<int>> &graph)
    {
        vis[node] = true;
        for(int &x : graph[node])
        {
            if(!vis[x])
                toposort(x, vis, topo, graph);
        }
        topo.push(node);
    }

    void dfs(int node, vector<bool> &vis, vector<vector<int>> &graph)
    {
        vis[node] = true;
        for(int &x : graph[node])
        {
            if(!vis[x])
                dfs(x, vis, graph);
        }
    }
    bool cycle(int node, vector<bool> &vis, vector<bool> dfsVis, vector<vector<int>> &graph)
    {
        vis[node] = dfsVis[node] = true;
        for(int &x : graph[node])
        {
            if(!vis[x] && cycle(x, vis, dfsVis, graph))
                return true;
            else if(dfsVis[x])
                return true;
        }
        dfsVis[node] = false;
        return false;
    }

    string alienOrder(vector<string> &words) {
        vector<bool> present(26, false);
        for(string &x : words)
            for(char &c : x)
                present[c - 'a'] = true;
        
        vector<vector<int>> graph(26);

        for(int i = 0; i < words.size() - 1; i++)
        {
            string str1 = words[i], str2 = words[i + 1];
            for(int j = 0; j < str1.size(); j++)
            {
                if(j >= str2.size())
                    return "";
                if(str1[j] != str2[j])
                {
                    if(find(graph[str1[j] - 'a'].begin(), graph[str1[j] - 'a'].end(), str2[j] - 'a') == graph[str1[j] - 'a'].end())
                        graph[str1[j] - 'a'].push_back(str2[j] - 'a');
                    break;
                }
            }
        }

        vector<bool> vis(26, false), dfsVis(26, false);
        for(int i = 0; i < 26; i++)
            if(!vis[i] && cycle(i, vis, dfsVis, graph))
                return "";
        
        fill(vis.begin(), vis.end(), false);
        stack<int> topo;
        for(int i = 0; i < 26; i++)
            if(present[i] && !vis[i])
                toposort(i, vis, topo, graph);
        
        fill(vis.begin(), vis.end(), false);
        priority_queue<int, vector<int>, greater<int>> cache;   //min heap;
        while(!topo.empty())
        {
            int node = topo.top();  topo.pop();
            if(vis[node])
                continue;
            dfs(node, vis, graph);
            cache.push(node);
        }

        string result = "";
        while(!cache.empty())
        {
            int node = cache.top(); cache.pop();
            for(int &x : graph[node])
                cache.push(x);
            result += (node + 'a');
        }
        return result;
    }
};
