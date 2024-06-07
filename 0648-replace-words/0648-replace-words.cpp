class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        int n = s.length();
        unordered_set<string> st;
        for(auto& it: d) st.insert(it);
        bool f = 1;
        string ans = "", curr = "";
        for(int i = 0; i < n; i++){
            if(s[i] == ' '){
                curr += s[i];
                f = 1;
                ans += curr;
                curr = "";
            }
            else{
                if(f){
                    curr += s[i];
                    if(st.count(curr) > 0){
                        ans += curr;
                        f = 0;
                        curr = "";
                    }
                }
            }
        }
        ans += curr;
        return ans;
    }
};