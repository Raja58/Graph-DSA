// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Dec 2021
//  @Detail  :        Max Area of Island (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    int dfs(int i, int j, int &m, int &n, vector<vector<int>> &grid)
    {
        grid[i][j] = -1;
        const vector<int> di{1, 0, 0, -1}, dj{0, -1, 1, 0};
        int result = 0;
        for(int k = 0; k < 4; k++)
        {
            int newI = i + di[k], newJ = j + dj[k];
            if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && grid[newI][newJ] == 1)
                result += dfs(newI, newJ, m, n, grid);
        }
        return 1 + result;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), result = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            if(grid[i][j] == 1)
            {
                int temp = dfs(i, j, m, n, grid);
                if(result < temp)
                    result = temp;
            }
        return result;
    }
};
