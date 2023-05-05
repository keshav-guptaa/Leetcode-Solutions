class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int ct = 0, ans = 0;
        int i = 0;
        for(; i < k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                ct++;
            }
        }
        ans = max(ans, ct);
        while(i < n){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                ct++;
            }
            if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u'){
                ct--;
            }
            ans = max(ans, ct);
            i++;
        }
        return ans;
    }
};