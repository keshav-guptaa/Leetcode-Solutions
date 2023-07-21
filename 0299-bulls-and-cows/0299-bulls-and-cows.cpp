class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        int n = secret.length();
        int bulls = 0, tot = 0;
        for(int i = 0; i < n; i++){
            m1[secret[i]-'0']++;
            m2[guess[i]-'0']++;
            if(secret[i] == guess[i]) bulls++;
        }
        for(int i = 0; i <= 9; i++) tot += min(m1[i], m2[i]);
        string ans = to_string(bulls) + "A" + to_string(tot-bulls) + "B";
        
        return ans;
    }
};