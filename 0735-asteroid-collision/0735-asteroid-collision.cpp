class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        for(int i = 0; i < a.size(); i++){
            if(a[i] < 0){
                bool f = 1;
                while(!st.empty() && st.top() > 0){
                    if(st.top() >= abs(a[i])){
                        f = 0;
                        if(st.top() == abs(a[i])) st.pop();
                        break;
                    } 
                    else st.pop();
                }
                if(f) st.push(a[i]);
            }
            else st.push(a[i]);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        } 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};