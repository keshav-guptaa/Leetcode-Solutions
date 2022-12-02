//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    queue<pair<pair<int, int>, int>> q;
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    vector<vector<int>> dist(n, vector<int>(m, 0));
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            if(grid[i][j]){
	                vis[i][j] = 1;
	                q.push({{i, j}, 0});
	            }
	        }
	    }
	    
	    int delrow[4] = {-1, 0, 0, 1};
	    int delcol[4] = {0, -1, 1, 0};
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int dis = q.front().second;
	        q.pop();
	        dist[row][col] = dis;
	        
	        for(int i = 0; i < 4; i++){
	            int newrow = delrow[i] + row;
	            int newcol = delcol[i] + col;
	            
	            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && 
	            vis[newrow][newcol] != 1){
	                q.push({{newrow, newcol}, dis+1});
	                vis[newrow][newcol] = 1;
	            }
	        }
	    }
	    return dist;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends