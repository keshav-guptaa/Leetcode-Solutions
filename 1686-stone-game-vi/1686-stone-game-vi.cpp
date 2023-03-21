class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        priority_queue<pair<int, pair<int, int>>> pq;
        int n = a.size();
        for(int i = 0; i < n; i++){
            pq.push({a[i]+b[i], {a[i], b[i]}});
        }
        int a1 = 0, b1 = 0;
        int f = 0;
        while(!pq.empty()){
            if(f) b1 += pq.top().second.second;
            else a1 += pq.top().second.first;
            pq.pop();
            f = 1-f;
        }
        if(a1 > b1) return 1;
        else if(a1 < b1) return -1;
        return 0;
    }
};