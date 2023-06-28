class Solution {
public:
    int dr[4] = {-1, 0, 0, 1};
    int dc[4] = {0, -1, 1, 0};
    
    bool f(int idx, int r, int c, vector<vector<char>>& b, string& word, int n, int m,
           vector<vector<int>>& vis){
        if(idx == word.length()-1 && word[idx] == b[r][c]) return true;
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] 
               && word[idx+1] == b[nr][nc]){
                //cout << word[idx] << endl;
                if(f(idx+1, nr, nc, b, word, n, m, vis)){
                    return true;
                } 
            }
        }
        vis[r][c] = 0;
        return false;
    }
    
    bool exist(vector<vector<char>>& b, string word) {
        int n = b.size(), m = b[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(word[0] == b[i][j]){
                    if(f(0, i, j, b, word, n, m, vis)) return true;
                }
            }
        }
        return false;
    }
};