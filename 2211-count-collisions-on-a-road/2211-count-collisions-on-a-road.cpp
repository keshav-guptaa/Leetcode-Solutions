class Solution {
public:
    int countCollisions(string d) {
        stack<char> st;
        int ans = 0;
        for(int i = 0; i < d.length(); i++){
            if(d[i] == 'R'){
                st.push(d[i]);
            }
            else if(d[i] == 'L'){
                if(!st.empty()){
                    if(st.top() == 'S') ans++;
                    else{
                        ans += 2;
                        st.pop();
                        while(!st.empty() && st.top() == 'R'){
                            ans++;
                            st.pop();
                        }
                        st.push('S');
                    }
                }
            }
            else{
                if(!st.empty()){
                    if(st.top() == 'S') st.push(d[i]);
                    else{
                        while(!st.empty() && st.top() == 'R'){
                            ans++;
                            st.pop();
                        }
                        st.push('S');
                    }
                }
                else st.push(d[i]);
            }
        }
        return ans;
    }
};