class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> m;
        int n = target.size();
        for(int i = 0; i < n; i++){
            m[target[i]] = i;
        }
        vector<int> idx;
        for(auto& it: arr){
            if(m.count(it) > 0) idx.push_back(m[it]);
        }
        vector<int> lis;
        if(idx.size() != 0) lis.push_back(idx[0]);
        for(auto& it: idx){
            if(it > lis.back()) lis.push_back(it);
            else{
                auto id = lower_bound(lis.begin(), lis.end(), it) - lis.begin();
                lis[id] = it;
            }
        }
        cout << lis.size() << endl;
        return n - lis.size();
    }
};