// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Dec 2021
//  @Detail  :        Snakes and Ladders (HackerRank)
//  ============================
//  -->

struct detail{
    int node;
    int move;
    bool operator<(const detail &x) const{
        return move > x.move;
    }
};

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    vector<int> graph(101, -1);
    vector<int> distance(101, INT_MAX);
    distance[1] = 0;
    for(vector<int> &x : ladders)
        graph[x[0]] = x[1];
    for(vector<int> &x : snakes)
        graph[x[0]] = x[1];
    
    priority_queue<detail> cache;
    cache.push({1, 0});
    while(!cache.empty())
    {
        auto itr = cache.top(); cache.pop();
        int curNode = itr.node, dis = itr.move;
        for(int step = 1; step <= 6; step++)
        {
            if(curNode + step == 100)
                return dis + 1;
            if(curNode + step > 100)
                break;
            if(graph[curNode + step] == 100)
                return dis + 1;
                
            if(graph[curNode + step] == -1 && distance[curNode + step] > dis + 1)
            {
                distance[curNode + step] = dis + 1;
                cache.push({curNode + step, dis + 1});
            }
                
            if(graph[curNode + step] != -1 && distance[graph[curNode + step]] > dis + 1)
            {
                distance[graph[curNode + step]] = dis + 1;
                cache.push({graph[curNode + step], dis + 1});
            }
        }
    }
    return -1;
}
