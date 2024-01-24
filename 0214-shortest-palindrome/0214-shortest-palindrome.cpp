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
    
    
    //In other words, the problem statement is find the longest palindrome substring starting from index zero, then, the remaining string, we have to reverse and add it in starting.
    string shortestPalindrome(string s) {
        string r_s = s;
        reverse(r_s.begin(), r_s.end());
        //How this temp string help us to find longest palindrome substring,
        //"#" is reseting len = 0 in lps, now think in this way, in lps, at last index, there is last character of r_s, which is first character of s, so whatever stored here is telling us longest suffix == longest prefix in temp, which is nothing but longest palindrome substring starting from index zero, try to make lps array for s = "abaceba" on copy.
        string temp = s + "#" + r_s;
        vector<int> lps = calcLPS(temp);
        
        int idx = lps.back();
        string extra = s.substr(idx);
        reverse(extra.begin(), extra.end());
        return extra + s;
    }
};