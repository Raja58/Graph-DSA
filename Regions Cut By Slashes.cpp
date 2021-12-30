// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        30 Dec 2021
//  @Detail  :        Regions Cut By Slashes (LeetCode)
//  ============================
//  -->

class Solution {
public:
    vector<int> di{-1, 0, 0, 1}, dj{0, -1, 1, 0};
    
    void dfs(int x, int y, int n, vector<vector<int>> &graph)
    {
        graph[x][y] = 0;
        for(int k = 0; k < 4; k++)
        {
            int newX = x + di[k], newY = y + dj[k];
            if(newX >= 0 && newX < n && newY >= 0 && newY < n && graph[newX][newY] == 1)
                dfs(newX, newY, n, graph);
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> graph(3 * n, vector<int>(3 * n, 1));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '/')
                {
                    int row = 3 * i, col = 3 * j + 2;
                    for(int cnt = 0; cnt < 3; cnt++)
                    {
                        graph[row][col] = 0;
                        row++;  col--;
                    }
                }
                else if(grid[i][j] != ' ')
                {
                    int row = 3 * i, col = 3 * j;
                    for(int cnt = 0; cnt < 3; cnt++)
                    {
                        graph[row][col] = 0;
                        row++;  col++;
                    }
                }
            }
        }
        
        int result = 0;
        for(int i = 0; i < 3 * n; i++)
            for(int j = 0; j < 3 * n; j++)
            {
                if(graph[i][j] == 1)
                {
                    dfs(i, j, 3 * n, graph);
                    result++;
                }
            }
        return result;
    }
};
