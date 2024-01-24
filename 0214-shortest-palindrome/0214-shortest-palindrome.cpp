class Solution {
public:
    vector<int> calcLPS(string& pattern){
        int n = pattern.length(), i = 1, len = 0;
        vector<int> lps(n, 0);
        while(i < n){
            if(pattern[i] == pattern[len]) lps[i++] = ++len;
            else{
                if(len != 0) len = lps[len-1];
                else i++;
            }
        }
        return lps;
    }
    
    string shortestPalindrome(string s) {
        string r_s = s;
        reverse(r_s.begin(), r_s.end());
        string temp = s + "#" + r_s;
        vector<int> lps = calcLPS(temp);
        
        int idx = lps.back();
        string extra = s.substr(idx);
        reverse(extra.begin(), extra.end());
        return extra + s;
    }
};