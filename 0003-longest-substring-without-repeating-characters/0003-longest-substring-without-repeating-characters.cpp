class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        char rep;
        int ans = INT_MIN;
        int size = s.length();
        int i = 0, j = 0;
        set<char> st;
        while(j < size){
            if(st.find(s[j]) == st.end()){
                ans = max(ans, j - i + 1);
                st.insert(s[j]);
            }
            else{
                rep = s[j];
                while(s[i] != rep){
                    st.erase(s[i]);
                    i++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};