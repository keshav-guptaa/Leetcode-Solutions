class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> nexta(n), nextb(n), nextc(n);
        int tempa = -1, tempb = -1, tempc = -1;
        for(int i = n-1; i >= 0; i--){
            nexta[i] = tempa;
            nextb[i] = tempb;
            nextc[i] = tempc;
            
            if(s[i] == 'a') tempa = i;
            if(s[i] == 'b') tempb = i;
            if(s[i] == 'c') tempc = i;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a' && nextb[i] != -1 && nextc[i] != -1){
                ans = ans + n - max(nextb[i], nextc[i]);
            }
            if(s[i] == 'b' && nexta[i] != -1 && nextc[i] != -1){
                ans = ans + n - max(nexta[i], nextc[i]);
            }
            if(s[i] == 'c' && nextb[i] != -1 && nexta[i] != -1){
                ans = ans + n - max(nextb[i], nexta[i]);
            }
        }
        return ans;
    }
};