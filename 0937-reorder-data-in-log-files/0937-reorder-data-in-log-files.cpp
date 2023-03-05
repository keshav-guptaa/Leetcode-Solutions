class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& A) {
        vector<pair<string, string>> let;
    vector<pair<string, string>> dig;
    for(auto x: A){
        bool f = 0;
        string s = "";
        string t = "";
        for(int i = 0; i < (int)x.size(); i++){
            if(x[i] == ' ' && f == 0){
                f = 1;
                continue;
            }
            if(f == 1) t += (char)(x[i]);
            else s += (char)(x[i]);
        }
        if(t[0] >= 'a' && t[0] <= 'z') let.push_back({t,s});
        else dig.push_back({t,s});
    }
    sort(let.begin(), let.end());
    vector<string> ans;
    for(auto it: let){
        ans.push_back((string)it.second+" "+it.first);
    }
    for(auto it: dig){
        ans.push_back((string)it.second+" "+it.first);
    }
    return ans;
    }
};