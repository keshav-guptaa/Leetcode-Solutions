
class Solution {
public:
    int mod = 1000000007;
    vector<int> dp;
    
    int f(int idx, string &s, int k){
        if(idx == s.length()) return 1;
        if(dp[idx] != -1) return dp[idx];
        
        long long curr = 0, ways = 0;
        for(int i = idx; i < s.length(); i++){
            int digit = s[i]-'0';
            curr = (curr*10) + digit;
            if(curr < 1 || curr > k) break;
            int ct = f(i+1, s, k);
            ways = (ways + ct)%mod;
        }
        
        return dp[idx] = ways;
    }
    
    int numberOfArrays(string s, int k) {
        int n = s.length();
        dp.resize(n, -1);
        return f(0, s, k);
    }
};
/*
class Solution {
public:
    int MOD = 1000000007;
    int solve(string& s, int& k, vector<int>&dp, int startIdx)
    {
        if (startIdx == s.size()) return 1;
        
        if (dp[startIdx] != -1) return dp[startIdx]; //retrieve results
        long long currNum = 0, ways = 0;
        //=================================================
        for (int i = startIdx; i < s.size(); i++)
        {
            int currDig = s[i] - '0';
            currNum = (currNum * 10) + currDig; //building the number from L->R

            if (currNum < 1 || currNum > k) break;
            int nextWays = solve(s, k, dp, i + 1);
            ways = (ways +  nextWays) % MOD;
        }
        //====================================================
        return dp[startIdx] = ways; //store results
    }
    int numberOfArrays(string s, int k) 
    {
        vector<int>dp(s.size(), -1);
        int ans = solve(s, k, dp, 0);
        return ans;
    }
};
*/