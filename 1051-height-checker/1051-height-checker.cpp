class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> temp = h;
        sort(temp.begin(), temp.end());
        int ans = 0;
        for(int i = 0; i < h.size(); i++){
            if(h[i] != temp[i]) ans++;
        }
        return ans;
    }
};