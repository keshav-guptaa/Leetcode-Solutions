class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        int n = points.size();
        for(int i = 0; i < n; i++){
            int x = points[i][0];
            int y = points[i][1];
            int z = pow(x, 2) + pow(y, 2);
            maxHeap.push({z, {x, y}});
            if(maxHeap.size() > k) maxHeap.pop();
        }
        int i = 0;
        vector<vector<int>> ans;
        while(!maxHeap.empty()){
            auto it = maxHeap.top();
            maxHeap.pop();
            ans.push_back({it.second.first, it.second.second});
        }
        return ans;
    }
};