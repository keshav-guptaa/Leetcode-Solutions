class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for(int i = 0; i < n; i++){
            for(auto& it: words[i]){
                freq[i][it-'a']++;
            }
        }
        
        vector<string> ans;
        for(int j = 0; j < 26; j++){
            int mn = 1e6;
            for(int i = 0; i < n; i++){
                mn = min(mn, freq[i][j]);
            }
            
            for(int i = 0; i < mn; i++){
                string s = "";
                s += j + 'a';
                ans.push_back(s);
            } 
        }
        return ans;
    }
};