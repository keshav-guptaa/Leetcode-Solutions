//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[105][105];

    int f(int i, int j, int arr[]){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 1e9;
        for(int k = i; k < j; k++){
            int x = f(i, k, arr) + f(k+1, j, arr) + arr[i-1]*arr[k]*arr[j];
            ans = min(ans, x);
        }
        return dp[i][j] = ans;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp, 0, sizeof(dp));
        
        for(int i = N-1; i >= 1; i--){
            for(int j = i+1; j < N; j++){
                int ans = 1e9;
                for(int k = i; k < j; k++){
                    int x = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    ans = min(ans, x);
                }
                dp[i][j] = ans;
            }
        }
        
        return dp[1][N-1];
        //return f(1, N-1, arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends