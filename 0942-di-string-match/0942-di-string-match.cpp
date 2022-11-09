class Solution {
public:
    vector<int> diStringMatch(string s) {
        int st = 0;
        int e = s.length();
        vector<int> ans;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'I'){
                ans.push_back(st);
                st++;
            }
            else{
                ans.push_back(e);
                e--;
            }
        }
        ans.push_back(e);
        return ans;
    }
};