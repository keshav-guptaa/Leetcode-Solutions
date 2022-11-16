class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> st;
        string ans = "";
        if(pattern[0] == 'I') ans += '1';
        else st.push('1');
        for(int i = 1; i <= pattern.length(); i++){
            if(pattern[i-1] == 'I'){
                while(!st.empty()){
                    ans += st.top();
                    st.pop();
                }
            }
            st.push('0' + i + 1);
        }
        while(!st.empty()){ 
            ans += st.top(); 
            st.pop();  
        }
        return ans;
    }
};