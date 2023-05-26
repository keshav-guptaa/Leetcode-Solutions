class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> m;
        int i = 0, j = 0, n = s.length();
        int mxfreq = 0, ans = 0;
        while(j < n){
            mxfreq = 0;
            m[s[j]]++;
            for(auto &x: m) mxfreq = max(mxfreq, x.second);
            
            if(j - i + 1 - mxfreq <= k){
                ans = max(ans, j-i+1);
            }
            else{
                while(j - i + 1 - mxfreq > k){
                    m[s[i++]]--;
                    for(auto &x: m) mxfreq = max(mxfreq, x.second);
                }
            }
            j++;
        }
        return ans;
    }
};