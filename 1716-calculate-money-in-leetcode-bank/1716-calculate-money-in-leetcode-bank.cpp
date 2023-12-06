class Solution {
public:
    int totalMoney(int n) {
        int ans = 0, ct = 0;
        for(int i = 1; i <= n; i++){
            if(i%7 == 1) ct = (i/7)+1;
            ans += ct++;
        }
        return ans;
    }
};