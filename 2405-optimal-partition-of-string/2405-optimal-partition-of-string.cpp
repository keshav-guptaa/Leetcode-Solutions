class Solution {
public:
    int partitionString(string s) {
        set<char> st;
        int ans = 1;
        for(int i = 0; i < s.length(); i++){
            if(st.find(s[i]) == st.end()){
                st.insert(s[i]);
            }
            else{
                st.erase(st.begin(), st.end());
                st.insert(s[i]);
                ans++;
            }
        }
        return ans;
    }
};