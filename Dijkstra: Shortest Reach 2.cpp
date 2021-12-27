// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Dec 2021
//  @Detail  :        Dijkstra: Shortest Reach 2 (HackerRank)
//  ============================
//  -->

struct detail{
    int node;
    int dist;
    bool operator<(const detail &x) const{
        return dist > x.dist;
    }
};

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    vector<unordered_map<int, int>> path(n + 1);
    for(vector<int> &x : edges)
    {
        if(path[x[0]].find(x[1]) != path[x[0]].end())
        {
            if(path[x[0]][x[1]] > x[2])
            {
                path[x[0]][x[1]] = x[2];
                path[x[1]][x[0]] = x[2];
            }
        }
        else
        {
            path[x[0]][x[1]] = x[2];
            path[x[1]][x[0]] = x[2];
        }
    }
    
    vector<vector<detail>> graph(n + 1);
    for(int i = 1; i <= n; i++)
    {
        for(auto &x : path[i])
        {
            graph[i].push_back({x.first, x.second});
        }
    }
    
    vector<int> dis(n + 1, INT_MAX);
    dis[s] = 0;
    priority_queue<detail> cache;
    cache.push({s, 0});
    while(!cache.empty())
    {
        detail temp = cache.top();  cache.pop();
        for(detail &x : graph[temp.node])
        {
            if(dis[x.node] > temp.dist + x.dist)
            {
                dis[x.node] = temp.dist + x.dist;
                cache.push({x.node, temp.dist + x.dist});
            }
        }
    }
    dis.erase(dis.begin() + s, dis.begin() + s + 1);
    dis.erase(dis.begin(), dis.begin() + 1);
    for(int &x : dis)
        if(x == INT_MAX)
            x = -1;
    return dis;
}
