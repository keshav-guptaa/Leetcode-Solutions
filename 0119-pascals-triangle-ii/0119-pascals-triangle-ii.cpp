class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        vector<int> ans;
        prev.push_back(1);
        if(rowIndex == 0) return prev;
        prev.push_back(1);
        if(rowIndex == 1) return prev;
        for(int i = 2; i <= rowIndex; i++){
            ans.resize(i+1, 0);
            ans[0] = 1;
            ans[i] = 1;
            for(int j = 1; j < i; j++){
                ans[j] = prev[j] + prev[j-1];
            }
            prev.resize(i+1);
            prev = ans;
        }
        return prev;
    }
};