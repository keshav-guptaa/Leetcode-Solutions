class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> more;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(capacity[i] == rocks[i]) ans++;
            else{
                more.push_back(capacity[i] - rocks[i]);
            }
        }
        sort(more.begin(), more.end());
        for(auto x: more){
            ans++;
            additionalRocks -= x;
            if(additionalRocks < 0){
                ans--;
                break;
            }
        }
        return ans;
    }
};