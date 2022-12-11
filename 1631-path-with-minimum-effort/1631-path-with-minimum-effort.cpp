class Solution {
public:
    typedef pair<int, pair<int, int>> ppi;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> maxi(n, vector<int>(m, 1e9));
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        pq.push({0, {0, 0}});
        maxi[0][0] = 0;
        int drow[4] = {0, 1, -1, 0};
        int dcol[4] = {-1, 0, 0, 1};
        
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int mx = pq.top().first;
            pq.pop();
            
            if(row == n-1 && col == m-1) return mx;
            
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m ){
                    int dif = abs(heights[row][col] - heights[nrow][ncol]);
                    int ma = max(dif, mx);
                    if(ma < maxi[nrow][ncol]){
                        maxi[nrow][ncol] = ma;
                        pq.push({ma, {nrow, ncol}});
                    }
                    
                }
            }
            
        }
        return 0;
    }
};