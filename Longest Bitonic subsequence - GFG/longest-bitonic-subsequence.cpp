//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>a)
	{
	    // code here
	    int n = a.size();
	    vector<int> dp(n, 1), dp2(n, 1);
    
       for(int i = 0; i < n; i++){
           for(int prev = 0; prev < i; prev++){
               if(a[prev] < a[i]){
                   dp[i] = max(dp[i], 1+dp[prev]);
               }
           }
       }
       reverse(a.begin(), a.end());
       for(int i = 0; i < n; i++){
           for(int prev = 0; prev < i; prev++){
               if(a[prev] < a[i]){
                   dp2[i] = max(dp2[i], 1+dp2[prev]);
               }
           }
       }
       int ans = 0;
       for(int i = 0; i < n; i++){
           ans = max(ans, dp[i] + dp2[n-1-i]-1);
       }
       return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends