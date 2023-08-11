class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& s) {
        int ct0 = count(st.begin(), st.end(), 0);
        int ct1 = count(st.begin(), st.end(), 1);
        queue<int> q;
        for(auto &it: st) q.push(it);
        int j = 0;
        while(!q.empty()){
            if((s[j] == 0 && ct0 == 0) || (s[j] == 1 && ct1 == 0)) return q.size();
            if(q.front() == s[j]){
                if(s[j] == 1) ct1--;
                else ct0--;
                j++;
                q.pop();
            }
            else{
                q.push(q.front());
                q.pop();
            }
        }
        return 0;
    }
};