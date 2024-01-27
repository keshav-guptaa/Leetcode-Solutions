class Solution {
public:
    vector<bool> visited;
    int n, mod = 1e9+7;
    vector<vector<int>> dp;
    
    int func(int prev,int id,string &str){
        if(id == n) return dp[id][prev] = 1; 
        if(dp[id][prev] != -1)  return dp[id][prev];
        
        visited[prev] = true;
        long long ans = 0;
        
        if(str[id] == 'D'){
            for(int i=prev-1;i>=0;i--){
                if(!visited[i]) ans = (ans + func(i,id+1,str))%mod;
            } 
        }
        else{
            for(int i=prev+1;i<=n;i++){
                if(!visited[i]) ans = (ans + func(i,id+1,str))%mod;
            } 
        }
        visited[prev] = false;
        return dp[id][prev] = ans;
    }
    int numPermsDISequence(string s) {
        n = s.size();
        visited = vector<bool>(n,0);
        dp = vector<vector<int> > (n+1,vector<int>(n+1,-1));
        long long ans = 0;
        for(int i=0;i<=n;i++)
        {
            ans = (ans + func(i,0,s))%mod;
        }
        return ans;
    }
};