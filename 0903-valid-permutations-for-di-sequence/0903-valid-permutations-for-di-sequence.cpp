class Solution {
public:
    vector<bool> visited;
    int n, mod = 1e9+7;
    vector<vector<int>> dp;
    
    int func(int idx, int num, string &str){
        if(idx == n) return 1; 
        if(dp[idx][num] != -1)  return dp[idx][num];
        
        visited[num] = true;
        long long ans = 0;
        
        if(str[idx] == 'D'){
            for(int i = num-1; i >= 0; i--){
                if(!visited[i]) ans = (ans + func(idx+1, i, str)) % mod;
            } 
        }
        else{
            for(int i = num+1; i <= n; i++){
                if(!visited[i]) ans = (ans + func(idx+1, i, str)) % mod;
            } 
        }
        visited[num] = false;
        return dp[idx][num] = ans;
    }
    int numPermsDISequence(string s) {
        n = s.size();
        visited = vector<bool>(n,0);
        dp = vector<vector<int>> (n+1, vector<int>(n+1, -1));
        long long ans = 0;
        for(int i = 0; i <= n; i++){
            ans = (ans + func(0, i, s))%mod;
        }
        return ans;
    }
};