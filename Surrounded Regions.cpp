// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Dec 2021
//  @Detail  :        Surrounded Regions (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    void bfs(int i, int j, int &m, int &n, vector<vector<char>> &board)
    {
        queue<pair<int, int>> cache;
        const vector<int> di{1, 0, 0, -1}, dj{0, -1, 1, 0};
        board[i][j] = '*';
        cache.push({i, j});
        while(!cache.empty())
        {
            pair<int, int> temp = cache.front();    cache.pop();
            for(int k = 0; k < 4; k++)
            {
                int newI = temp.first + di[k], newJ = temp.second + dj[k];
                if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && board[newI][newJ] == 'O')
                {
                    board[newI][newJ] = '*';
                    cache.push({newI, newJ});
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O')
                bfs(i, 0, m, n, board);
            if(board[i][n - 1] == 'O')
                bfs(i, n - 1, m, n, board);
        }
        
        for(int j = 0; j < n; j++)
        {
            if(board[0][j] == 'O')
                bfs(0, j, m, n, board);
            if(board[m - 1][j] == 'O')
                bfs(m - 1, j, m, n, board);
        }
        
        for(int i = 1; i < m - 1; i++)
            for(int j = 1; j < n - 1; j++)
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == '*')
                    board[i][j] = 'O';
    }
};
