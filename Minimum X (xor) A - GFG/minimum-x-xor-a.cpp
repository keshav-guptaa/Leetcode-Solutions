//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int req = __builtin_popcount(b);
        int req2 = __builtin_popcount(a);
        if(req == req2) return a;
        else{
            if(req > req2){
                int extra = req - req2;
                int x = a, i = 0;
                while(extra && x){
                    if(!(x & 1)){
                        a = (a | (1 << i));
                        extra--;
                    }
                    x >>= 1;
                    i++;
                }
            }
            else{
                int x = a, i = 0;
                int extra = req2 - req;
                while(x){
                    if(x&1){
                        if(extra > 0){
                            a = (a & (~(1 << i)));
                            extra--;
                        }
                    }
                    x >>= 1;
                    i++;
                }
            }
        }
        return a;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends