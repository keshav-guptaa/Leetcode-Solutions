//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
        // Code here
        sort(ranges.begin(), ranges.end());
        vector<int> st(n);
        vector<int> sf(n);
        int mx = -1;
        for(int i = n-1; i >= 0; i--){
            mx = max(mx, ranges[i][2]);
            st[i] = ranges[i][0];
            sf[i] = mx;
        }
        int ans = -1, sum = 0;
        for(int i = 0; i < n; i++){
            sum = ranges[i][2];
            int idx = lower_bound(st.begin()+i+1, st.end(), ranges[i][1]) - st.begin();
            if(idx != n){
                sum += sf[idx];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends