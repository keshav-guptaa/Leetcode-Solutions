class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> m;
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            if(m.find(s) == m.end()){
                m[s] = ans.size();
                vector<string> t;
                t.push_back(strs[i]);
                ans.push_back(t);
            }
            else{
                ans[m[s]].push_back(strs[i]);
            }
        }
        return ans;
    }
};