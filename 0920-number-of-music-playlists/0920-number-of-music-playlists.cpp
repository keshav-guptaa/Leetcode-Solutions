class Solution {
public:
    const int mod = 1e9+7;
    int dp[105][105], n, goal;
    
    int f(int len, int unique, int k){
        if(len == goal){
            if(unique == n) return 1;
            return 0;
        }
        if(dp[len][unique] != -1) return dp[len][unique];
        
        long long newSong = (f(len+1, unique+1, k)*1LL*(n-unique))%mod;
        long long oldSong = 0;
        if(unique > k) oldSong = (f(len+1, unique, k)*1LL*(unique-k))%mod;
        return dp[len][unique] = (newSong + oldSong)%mod;
    }
    
    int numMusicPlaylists(int N, int GOAL, int k) {
        goal = GOAL, n = N;
        memset(dp, -1, sizeof dp);
        return f(0, 0, k);
    }
};