class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        int t = meet.size();
        unordered_map<int, int> m;
        sort(meet.begin(), meet.end());
        // time, index of used room
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq1;
        // index of unused room
        priority_queue<int, vector<int>, greater<int>> pq2;
        for(int i = 0; i < n; i++) pq2.push(i);
        for(int i = 0; i < meet.size(); i++){
            while(!pq1.empty() && pq1.top().first <= meet[i][0]){
                pq2.push(pq1.top().second);
                pq1.pop();
            }
            if(pq2.empty()){
                auto [time, room] = pq1.top();
                pq1.pop();
                m[room]++;
                pq1.push({time+0LL+meet[i][1]-meet[i][0], room});
            }
            else{
                m[pq2.top()]++;
                pq1.push({meet[i][1], pq2.top()});
                pq2.pop();
            }
        }
        int ans = -1, mx = 0;
        for(int i = 0; i < n; i++){
            if(m[i] > mx){
                mx = m[i];
                ans = i;
            }
        }
        return ans;
    }
};