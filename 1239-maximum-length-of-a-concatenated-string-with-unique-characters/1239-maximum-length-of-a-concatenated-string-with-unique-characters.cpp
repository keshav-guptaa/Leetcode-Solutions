class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size(), tot = 1 << n, ans = 0;
        for(int mask = 0; mask < tot; mask++){
            int sz = 0, seen = 0;
            bool f = 1;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    for(char ch: arr[i]){
                        int j = ch-'a';
                        if(seen & (1 << j)){
                            f = 0; break;
                        }
                        seen |= (1 << j);
                        sz++;
                        if(!f) break;
                    }
                }
                if(!f) break;
            }
            if(f && sz > ans) ans = sz;
        }
        return ans;
    }
};