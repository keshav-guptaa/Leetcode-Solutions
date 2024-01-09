class Solution {
public:
    long long nCr(int n, int r){
        long long ans = 1;
        for(int i = 1, j = n; i <= min(n-r, r); i++, j--) ans = (ans*j)/i;
        return ans;
    }
    
    string kthSmallestPath(vector<int>& d, int k) {
        int h = d[1], v = d[0], tot = h+v;
        string ans = "";
        long long c;
        for(int i = 0; i < tot; i++){
            if(h){
                c = nCr(h+v-1, v);
                if(k <= c){
                    ans += 'H';
                    h--;
                }
                else{
                    ans += 'V';
                    v--;
                    k -= c;
                }
            }
            else{
                ans += 'V';
                v--;
            }
        }
        return ans;
    }
};