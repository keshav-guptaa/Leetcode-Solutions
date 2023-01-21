class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size(), fresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        //cout << fresh  << endl;
        int time = 0;
        int delrow[] = {-1,0,0,1};
        int delcol[] = {0,1,-1,0};
        while(!q.empty()){
            int sz = q.size();
            if(fresh != 0) time++;
            for(int i = 0; i < sz; i++){
                auto node = q.front();
                q.pop();
                int row = node.first;
                int col = node.second;
                for(int i = 0; i < 4; i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && 
                       grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        fresh--;
                    }
                }
            }
            
        }
        //cout << fresh  << endl;
        if(fresh) return -1;
        else return time;
    }
};