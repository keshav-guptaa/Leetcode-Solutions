class Solution {
public:
    int maximumGap(vector<int>& A) {
        int n = A.size();
    if(n < 2) return 0;
    int mx = *max_element(A.begin(), A.end());
    int mn = *min_element(A.begin(), A.end());
    int len = (mx - mn + n - 2)/(n-1);
    vector<int> mxb(n-1, INT_MIN);
    vector<int> mnb(n-1, INT_MAX);
    for(int i = 0; i < n; i++){
        if(A[i] == mn || A[i] == mx) continue;
        
        int idx = (A[i] - mn)/len;
        mxb[idx] = max(mxb[idx], A[i]);
        mnb[idx] = min(mnb[idx], A[i]);
    }
    
    int prev = mn;
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(mnb[i] == INT_MAX) continue;
        
        ans = max(ans, mnb[i] - prev);
        prev = mxb[i];
    }
    ans = max(ans, mx-prev);
    return ans;
    }
};