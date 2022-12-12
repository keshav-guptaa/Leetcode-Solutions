//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int, int>> q;
        vector<int> dist(100000, 1e9);
        q.push({start, 0});
        dist[start] = 0;
        int m = 100000;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int steps = it.second;
            int node = it.first;
            if(node == end) return steps;
            
            for(int i = 0; i < arr.size(); i++){
                int newNode = arr[i]*node;
                newNode %= m;
                if(steps + 1 < dist[newNode]){
                    dist[newNode] = steps + 1;
                    q.push({newNode, steps + 1});
                }
            }
            
        }
        
        
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends