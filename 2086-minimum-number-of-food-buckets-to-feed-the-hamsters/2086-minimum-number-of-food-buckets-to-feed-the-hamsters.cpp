class Solution {
public:
    int minimumBuckets(string h) {
        int ans = 0;
        int n = h.length();
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(h[i] == 'H'){
                if(i > 0 && vis[i-1]) continue;
                if(i < h.length()-1 && h[i+1] == '.'){
                    ans++; 
                    vis[i+1] = 1;
                } 
                else if(i > 0 && h[i-1] == '.') ans++;
                else return -1;
            } 
        }
        return ans;
    }
};