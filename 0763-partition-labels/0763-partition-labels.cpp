class Solution {
public:
    vector<int> partitionLabels(string s) {
        int l = s.length();
        map<char, int> m;
        for(int i = 0; i < l; i++){
            m[s[i]]++;
        }
        vector<int> ans;
        vector<char> temp;
        int count = 0, x = 0;
        for(int i = 0; i < l; i++){
            x++;
            if(find(temp.begin(), temp.end(), s[i]) == temp.end()){
                count += m[s[i]];
                temp.push_back(s[i]);
            }
            
            if(count == x){
                ans.push_back(count);
                count = 0;
                x = 0;
                temp.clear();
            }
        }
        return ans;
        
    }
};