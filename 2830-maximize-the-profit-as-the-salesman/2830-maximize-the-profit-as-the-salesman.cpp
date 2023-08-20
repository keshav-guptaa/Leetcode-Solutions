class Solution {
public:
    int dp[100005];
    
    int f(int idx, vector<vector<int>>& offers, vector<int>& st){
        if(idx >= offers.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int mx = f(idx+1, offers, st);
        int nidx = upper_bound(st.begin(), st.end(), offers[idx][1]) - st.begin();
        mx = max(mx, offers[idx][2] + f(nidx, offers, st));
        return dp[idx] = mx;
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        vector<int> st;
        for(int i = 0; i < offers.size(); i++){
            st.push_back(offers[i][0]);
            //cout << st.back() << endl;
        } 
        memset(dp, -1, sizeof dp);
        return f(0, offers, st);
    }
};