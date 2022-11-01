//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++
#define ll long long
class Solution 
{
    bool isPossible(ll limit, int N, int M, int A[]){
        ll pages = 0;
        ll allocate = 1;
        for(int i = 0; i < N; i++){
            if(A[i] > limit) return false;
            
            if(pages + A[i] > limit){
                allocate++;
                pages = A[i];
            }
            else{
                pages += A[i];
            }
        }
        if(allocate > M) return false;
        return true;
    }
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        ll ans = -1;
        int start = 0;
        ll end = 0;
        if(N < M) return -1;
        for(int i = 0; i < N; i++){
            start = min(start, A[i]);
            end += A[i];
        }
        ll mid = start + (end - start)/2;
        while(start <= end){
            if(isPossible(mid, N, M, A)){
                ans = mid;
                end = mid-1;
            }
            else start = mid + 1;
            mid = start + (end - start)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends