class Solution {
public:
    int ans = 0;
    
    void recursion(int n, vector<int>& vis, int ct){
        if(ct == n){
            ans++;
            return;
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i] && (((ct+1)%i == 0) || (i%(ct+1) == 0))){
                vis[i] = 1;
                recursion(n, vis, ct+1);
                vis[i] = 0;
            }
        }
    }
    
    int countArrangement(int n) {
        vector<int> vis(n+1, 0);
        recursion(n, vis, 0);
        return ans;
    }
};