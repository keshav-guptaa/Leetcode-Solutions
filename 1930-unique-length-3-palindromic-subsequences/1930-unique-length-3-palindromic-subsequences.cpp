class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ct = 0;
        for(int i = 0; i < 26; i++){
            set<char> st;
            bool f = 0, f1 = 0;
            int ans = 0;
            for(auto &it: s){
                if(it == 'a'+i){
                    int x = st.size();
                    if(f1) ans = max(ans, x+1);
                    else ans = max(ans, x);
                    if(f) f1 = 1;
                    f = 1;
                }
                else if(f) st.insert(it);
            }
            ct += ans;
        }
        return ct;
    }
};