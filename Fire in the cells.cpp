// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        09 Jan 2022
//  @Detail  :        Fire in the cells (CodeStudio)
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;

struct detail{
    int x;
    int y;
    int dis;
};

bool notCorner(int x, int y, int n, int m)
{
    return !(x == 0 && y == 0) && !(x == 0 && y == m - 1) && !(x == n - 1 && y == 0) && !(x == n - 1 && y == m - 1);
}

int fireInTheCells(vector<vector<int>> &mat, int n, int m, int x, int y) {
    queue<detail> cache;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 1)
                mat[i][j] = INT_MAX;
    		    else
                cache.push({i, j, 0});
    
    vector<int> dx{-1, 0, 0, 1}, dy{0, -1, 1, 0};
    while(!cache.empty())
    {
        detail temp = cache.front();	cache.pop();
        for(int k = 0; k < 4; k++)
        {
            int newX = temp.x + dx[k], newY = temp.y + dy[k];
            if(newX >= 0 && newX < n && newY >= 0 && newY < m && mat[newX][newY] > 1 + temp.dis)
            {
                mat[newX][newY] = 1 + temp.dis;
                cache.push({newX, newY, 1 + temp.dis});
            }
        }
    }
    
    if(x == 0 || x == n - 1 || y == 0 || y == m - 1)
        if(notCorner(x, y, n, m))
        	return 0;
    cache.push({x, y, 0});
    mat[x][y] = INT_MIN;
    while(!cache.empty())
    {
        detail temp = cache.front();	cache.pop();
        for(int k = 0; k < 4; k++)
        {
            int newX = temp.x + dx[k], newY = temp.y + dy[k];
            if(newX >= 0 && newX < n && newY >= 0 && newY < m && mat[newX][newY] > 1 + temp.dis)
            {
                if(newX == 0 || newX == n - 1 || newY == 0 || newY == m - 1)
                    if(notCorner(newX, newY, n, m))
                    	return 1 + temp.dis;
                mat[newX][newY] = INT_MIN;
                cache.push({newX, newY, 1 + temp.dis});
            }
        }
    }
    return -1;
}
