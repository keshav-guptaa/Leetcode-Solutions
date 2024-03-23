class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        map<char, int> m;
        for(auto &it: s) m[it]++;
        
        int i = 0, j = 0, ans = n, k = n/4;
        while(j < n){
            m[s[j]]--;
            while (i < n && m['Q'] <= k && m['W'] <= k && m['E'] <= k && m['R'] <= k) {
                ans = min(ans, j - i + 1);
                m[s[i++]]++;
            }
            j++;
        }
        return ans;
    }
};