//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution{
  public:
  
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    vector<ll> bit;
    
    void update(ll i, ll x){
        for(; i < bit.size(); i += i & (-i)){
            bit[i] += x;
        }
    }
    
    ll sum(ll i){
        ll ans = 0;
        for(; i > 0; i -= i & (-i)){
            ans += bit[i];
        }
        return ans;
    }
    
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        bit.resize(n+1, 0);
        vector<pair<ll, ll>> v;
        for(ll i = 0; i < n; i++) v.push_back({arr[i], i});
        sort(v.begin(), v.end());
        vector<ll> c(n);
        c[v[0].second] = 1;
        ll prev = 1;
        for(ll i = 1; i < n; i++){
            if(v[i].first != v[i-1].first) prev++;
            c[v[i].second] = prev;
        }
        ll int ans = 0;
        for(ll i = 0; i < n; i++){
            update(c[i], 1);
            ans += sum(n) - sum(c[i]);
            //cout << c[i] << " ";
        }
        
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends