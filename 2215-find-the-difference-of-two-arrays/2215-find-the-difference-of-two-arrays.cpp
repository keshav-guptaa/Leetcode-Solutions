class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& n1, vector<int>& n2) {
        int n = n1.size(), m = n2.size();
        vector<vector<int>> ans(2);
        map<int, int> m1, m2;
        for(int i = 0; i < n; i++){
            bool f = 1;
            for(int j = 0; j < m; j++){
                if(n1[i] == n2[j]) f = 0;
            }
            if(f && m1[n1[i]] == 0){
                ans[0].push_back(n1[i]);
                m1[n1[i]]++;
            } 
        }
        for(int i = 0; i < m; i++){
            bool f = 1;
            for(int j = 0; j < n; j++){
                if(n2[i] == n1[j]) f = 0;
            }
            if(f && m2[n2[i]] == 0){
                ans[1].push_back(n2[i]);
                m2[n2[i]]++;
            } 
        }
        return ans;
    }
};