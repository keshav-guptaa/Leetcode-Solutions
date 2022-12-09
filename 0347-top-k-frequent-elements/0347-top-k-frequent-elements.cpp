class Solution {
public:
    typedef pair<int, int> pii;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto x: nums) m[x]++;
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        for(auto x: m){
            minHeap.push({x.second, x.first});
            if(minHeap.size() > k) minHeap.pop();
        }
        vector<int> ans;
        while(!minHeap.empty()){
            auto it = minHeap.top();
            minHeap.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};