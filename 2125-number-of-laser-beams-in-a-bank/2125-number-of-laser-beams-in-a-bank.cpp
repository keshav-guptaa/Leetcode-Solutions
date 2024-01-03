class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].length();
        int ans = 0, prev = 0, ct = 0;
        for(int i = 0; i < n; i++){
            ct = 0;
            for(int j = 0; j < m; j++){
                if(bank[i][j] == '1') ct++;
            }
            ans += prev*ct;
            cout << prev << " " << ct << " " << ans << endl;
            if(ct != 0) prev = ct;
        }
        return ans;
    }
};