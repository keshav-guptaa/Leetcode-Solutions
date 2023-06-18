//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int memo(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
        if(day < 0) return 0;
        if(dp[day][last] != -1) return dp[day][last];
        /*if(day == 0){
            int mx = 0;
            for(int i = 0; i <= 2; i++){
                if(i != last) mx = max(mx, points[day][i]);
            }
            return dp[day][last] = mx;
        }*/
        int mx = 0;
        for(int i = 0; i <= 2; i++){
            if(i != last){
                int curr = points[day][i] + memo(day-1, i, points, dp);
                mx = max(mx, curr);
            } 
        }
        return dp[day][last] = mx;
    }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return memo(n-1, 3, points, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends