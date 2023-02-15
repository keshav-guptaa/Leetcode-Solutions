//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    void bfs(queue<pair<int, int>> &q, vector<vector<int>> &vis, int drow[], 
             int dcol[], vector<vector<int>>& h){
        int n = h.size(), m = h[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            int d = h[row][col];
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                   h[nrow][ncol] >= d && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
            
        }
    }

    int water_flow(vector<vector<int>> &h,int n,int m){
    // Write your code here.
        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;
        vector<vector<int>> vis1(n, vector<int>(m, 0));
        vector<vector<int>> vis2(n, vector<int>(m, 0));
        
        int drow[] = {-1, 0, 0, 1};
        int dcol[] = {0, -1, 1, 0};
        
        for(int i = 0; i < n; i++){
            vis1[i][0] = 1;
            q1.push({i, 0});
            vis2[i][m-1] = 1;
            q2.push({i, m-1});
        }
        for(int i = 0; i < m; i++){
            vis1[0][i] = 1;
            q1.push({0, i});
            vis2[n-1][i] = 1;
            q2.push({n-1, i});
        }
        
        bfs(q1, vis1, drow, dcol, h);
        bfs(q2, vis2, drow, dcol, h);
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vis1[i][j] == 1 && vis2[i][j] == 1){
                    ans++;
                } 
            }
        }
        return ans;
    
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends