class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [](vector<int> &a, vector<int> &b){
            return a[0] > b[0];
        });
        unordered_set<int> s;
        long long curr = 0, ans = 0;
        vector<int> d;
        for(int i = 0; i < items.size(); i++){
            if(i < k){
                if(s.find(items[i][1]) != s.end()) d.push_back(items[i][0]); 
                curr += items[i][0];
                s.insert(items[i][1]);
            }
            else{
                if(s.find(items[i][1]) == s.end()){
                    if(d.size() == 0) break;
                    curr -= d.back();
                    curr += items[i][0];
                    d.pop_back();
                }
                s.insert(items[i][1]);
            }
            ans = fmax(ans, curr + s.size()*s.size());
        }
        return ans;
    }
};