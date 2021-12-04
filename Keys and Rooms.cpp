// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        04 Dec 2021
//  @Detail  :        Keys and Rooms (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &rooms)
    {
        vis[node] = true;
        
        for(int &x : rooms[node])
        {
            if(vis[x] == true)
                continue;
            dfs(x, vis, rooms);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(0, vis, rooms);
        return none_of(vis.begin(), vis.end(), [](bool x) {return x == false;});
    }
};
