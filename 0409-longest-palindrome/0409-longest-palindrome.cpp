class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for(auto& it: s) m[it]++;
        int ans = 0, ct = 0;
        for(auto& it: m){
            if(it.second & 1){
                ct++;
                ans += it.second-1;
            }
            else ans += it.second;
        }
        return ct > 0 ? ans + 1 : ans;
    }
};