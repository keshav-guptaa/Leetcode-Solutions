class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < mat.size(); i++){
            int ct = 0;
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 1) ct++;
            }
            pq.push({-ct, -i});
        }
        vector<int> ans;
        
        while(k--){
            ans.push_back(-pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};