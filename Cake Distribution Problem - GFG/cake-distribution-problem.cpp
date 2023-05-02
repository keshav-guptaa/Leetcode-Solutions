//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool f(int mid, vector<int>& sw, int N, int K){
        int req = 0, sum = 0;
        for(int i = 0; i < N; i++){
            sum += sw[i];
            if(sum >= mid){
                req++;
                sum = 0;
            }
        }
        return req >= K+1;
    }
    
    int maxSweetness(vector<int>& sw, int N, int K) {
        long long sum = 0, ans;
        for(int i = 0; i < N; i++) sum += sw[i];
        long long s = 0, e = sum, mid;
        while(s <= e){
            mid = s + (e-s)/2;
            if(f(mid, sw, N, K)){
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        return int(ans);
        
    // Write your code here.
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends