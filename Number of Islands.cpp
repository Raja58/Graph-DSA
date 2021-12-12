// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        12 Dec 2021
//  @Detail  :        Number of Islands (LeetCode)
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
                if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && board[newI][newJ] == '1')
                {
                    board[newI][newJ] = '*';
                    cache.push({newI, newJ});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), cnt = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == '1')
                    bfs(i, j, m, n, board), cnt++;
        return cnt;
    }
};
