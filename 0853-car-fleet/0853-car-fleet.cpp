class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {
        unordered_map<int, int> m;
        int n = p.size();
        for(int i = 0; i < n; i++){
            m[p[i]] = s[i];
        }
        sort(p.begin(), p.end());
        stack<double> st;
        for(int i = n-1; i >= 0; i--){
            double time = double(t-p[i])/m[p[i]];
            if(st.empty() || time > st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};