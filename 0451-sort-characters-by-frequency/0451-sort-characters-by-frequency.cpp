class Solution {
public:
    
    string frequencySort(string s) {
        map<char, int> m;
        string ans;
        for(int i = 0; i < s.length(); i++){
            m[s[i]]++;
        }
        vector<pair<int, char>> v;
        for(auto it: m){
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for(auto it: v){
            while(it.first--){
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};