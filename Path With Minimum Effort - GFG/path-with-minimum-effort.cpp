//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& h) {
        // Code here
        int n = h.size(), m = h[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 1e9));
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>> > pq;
        diff[0][0] = 0;
        pq.push({0, {0, 0}});
        int drow[] = {0, -1, 1, 0};
        int dcol[] = {1, 0, 0, -1};
        
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int d = pq.top().first;
            pq.pop();
            
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int df = abs(h[row][col] - h[nrow][ncol]);
                    if(max(d, df) < diff[nrow][ncol]){
                        diff[nrow][ncol] = max(d, df);
                        pq.push({diff[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return diff[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends