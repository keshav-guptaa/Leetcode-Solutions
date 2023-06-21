class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<int> pfOne(n), sfZero(n);
        int ans = min(count(s.begin(), s.end(), '1'), count(s.begin(), s.end(), '0'));
        int one = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') one++;
            pfOne[i] = one;
        }
        int zero = 0;
        for(int i = n-1; i >= 0; i--){
            sfZero[i] = zero;
            if(s[i] == '0') zero++;
        }
        for(int i = 0; i < n-1; i++){
            ans = min(ans, sfZero[i] + pfOne[i]);
        }
        return ans;
    }
};