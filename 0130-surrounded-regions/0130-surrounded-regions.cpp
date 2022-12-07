class Solution {
public:
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O' ){
                q.push({0,i});
                vis[0][i] = 1;
            } 
            if(board[n-1][i] == 'O'){
                q.push({n-1, i});
                vis[n-1][i] = 1;
            } 
        }
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                vis[i][0] = 1;
            } 
            if(board[i][m-1] == 'O'){
                q.push({i, m-1});
                vis[i][m-1] = 1;
            } 
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int drow[4] = {-1, 0, 0, 1};
            int dcol[4] = {0, -1, 1, 0};
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                  vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};