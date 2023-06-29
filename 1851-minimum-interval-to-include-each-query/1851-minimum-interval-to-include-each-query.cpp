#define pi pair<int, int>

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& in, vector<int>& q) {
        vector<int> q1 = q, ans(q.size());
        unordered_map<int, int> m;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        sort(in.begin(), in.end());
        sort(q.begin(), q.end());
        int j = 0;
        for(int i = 0; i < q.size(); i++){
            while(j < in.size() && in[j][0] <= q[i]){
                //PQ has size as well as right coordinate of interval
                pq.push({in[j][1]-in[j][0]+1, in[j][1]});
                j++;
            }
            while(!pq.empty() && pq.top().second < q[i]) pq.pop();
            if(pq.size() == 0) m[q[i]] = -1;
            else m[q[i]] = pq.top().first;
        }
        for(int i = 0; i < q.size(); i++){
            ans[i] = m[q1[i]];
        }
        return ans;
    }
};