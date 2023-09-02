class Solution {
public:
    unordered_set<string> st;
    vector<int> dp;

    int solve(string& s, int ind){ 
        if(ind >= s.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        int res = 1 + solve(s, ind + 1);   
        for(int i = 1; ind + i <= s.size(); ++i){
            string t = s.substr(ind, i);
            if(st.find(t) != st.end()) res = min(res, solve(s, ind+i));
        }
        return dp[ind] = res;
    }

    int minExtraChar(string s, vector<string>& dict) {
        dp.resize(s.size() + 1, -1);
        for(auto &d: dict) st.insert(d);
        return solve(s, 0);
    }
};