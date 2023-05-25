//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string s) {
	    // code here
	    int k = pat.length(), ct = 0;
	    map<char, int> m;
	    for(int i = 0; i < k; i++){
	        if(m[pat[i]] == 0) ct++;
	        m[pat[i]]++;
	    }
	    int i = 0, j = 0, n = s.length(), ans = 0;
	    while(j < n){
	        m[s[j]]--;
	        if(m[s[j]] == 0) ct--;
	        if(j-i+1 == k){
	            if(ct == 0) ans++;
	            m[s[i]]++;
	            if(m[s[i]] == 1) ct++;
	            i++;
	        }
	        j++;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends