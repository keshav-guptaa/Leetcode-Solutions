class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int col = strs[0].length();
        int n = strs.size();
        int ans = 0;
        for(int i = 0; i < col; i++){
            char prev = strs[0][i];
            for(int j = 1; j < n; j++){
                if(strs[j][i]-'0' < prev - '0'){
                    ans++;
                    break;
                }
                prev = strs[j][i];   
            }
        }
        return ans;
    }
};