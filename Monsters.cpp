// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        23 Jul 2021
//  @Detail  :        Monster (CSES Graph)
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;
#define int long long
 
vector<int> dx{1, -1, 0, 0}, dy{0, 0, -1, 1};
vector<char> dr{'D', 'U', 'L', 'R'};
 
struct detail{
    int x;
    int y;
};
 
struct box{
    int x;
    int y;
    int dis;
};
 
bool isLavaPossible(int &x, int &y, int &n, int &m,
        vector<vector<int>> &lava, vector<vector<char>> &grid)
{
    return 0 <= x && x < n && 0 <= y && y < m && (grid[x][y] == '.' || grid[x][y] == 'A') && lava[x][y] == -1;
}
 
bool isPossible(int &x, int &y, int &n, int &m, int time,
        vector<vector<char>> &grid, vector<vector<int>> &lava, vector<vector<int>> &path)
{
    bool cond = lava[x][y] == -1 || (lava[x][y] != -1 && lava[x][y] > time);
    return 0 <= x && x < n && 0 <= y && y < m && grid[x][y] == '.' && path[x][y] == -1 && cond;
}
 
bool isDestination(int &x, int &y, int &n, int &m)
{
    return x == 0 || x == n - 1 || y == 0 || y == m -1;
}
 
vector<vector<int>> updateLava(vector<detail> &monster, int &n, int &m, vector<vector<char>> &grid)
{
    vector<vector<int>> lava(n, vector<int>(m, -1));
    queue<box> cache;
    for(auto &z : monster)
    {
        lava[z.x][z.y] = 0;
        cache.push({z.x, z.y, 0});
    }
 
    while(!cache.empty())
    {
        box temp = cache.front();   cache.pop();        
        for(int i = 0; i < 4; i++)
        {
            int a = temp.x + dx[i], b = temp.y + dy[i];
            if(!isLavaPossible(a, b, n, m, lava, grid))
                continue;
            cache.push({a, b, temp.dis + 1});
            lava[a][b] = temp.dis + 1;
        }
    }
    return lava;
}
 
box getPathLen(int &n, int &m, detail &player, vector<vector<char>> &grid,
        vector<vector<int>> &lava, vector<vector<int>> &path)
{
    if(isDestination(player.x, player.y, n, m))
        return {player.x, player.y, 0};
    queue<box> cache;
    cache.push({player.x, player.y, 0});
    path[player.x][player.y] = 0;
    while(!cache.empty())
    {
        box temp = cache.front();   cache.pop();
        for(int i = 0; i < 4; i++)
        {
            int a = temp.x + dx[i], b = temp.y + dy[i];
            if(!isPossible(a, b, n, m, temp.dis + 1, grid, lava, path))
                continue;
            cache.push({a, b, temp.dis + 1});
            path[a][b] = i;
            if(isDestination(a, b, n, m))
                return {a, b, temp.dis + 1};
        }
    }
    return {-1, -1, -1};
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;   cin>>n>>m;    
    vector<vector<char>> grid(n, vector<char>(m));    
    vector<detail> monster;
    detail player;
    for(int i = 0; i < n; i++)
        for(int  j = 0; j < m; j++)
        {
            cin>>grid[i][j];
            if(grid[i][j] == 'A')
                player = {i, j};
            else if(grid[i][j] == 'M')
                monster.push_back({i, j});
        }
    
    vector<vector<int>> lava = updateLava(monster, n, m, grid), path(n, vector<int>(m, -1));
    box result = getPathLen(n, m, player, grid, lava, path);
    if(result.dis == -1)
        cout<<"NO";
    else
    {
        vector<char> final(result.dis);
        int k = result.dis - 1;
        pair<int, int> start{player.x, player.y}, end{result.x, result.y};
        
        while(end != start)
        {
            int idx = path[end.first][end.second];
            final[k--] = dr[idx];
            end = {end.first - dx[idx], end.second - dy[idx]};
        }
        cout<<"YES"<<"\n"<<result.dis<<"\n";
        for(char &z : final)
            cout<<z;
    }
    return 0;
}
