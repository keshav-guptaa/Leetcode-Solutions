//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j=0; j<n; j++){
        dp[0][j] = matrix[0][j];
    }
    
    for(int i=1; i<n; i++){
        for(int j=0;j<n;j++){
            
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += -1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<n) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += -1e9;
            
            dp[i][j] = max(up, max(leftDiagonal,rightDiagonal));
            
        }
    }
    
    int maxi = INT_MIN;
    
    for(int j=0; j<n;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    
    return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends