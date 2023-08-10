class Solution {
public:
    int minRefuelStops(int t, int st, vector<vector<int>>& s) {
        int curr = st, stops = 0;
        priority_queue<int> pq;
        for(int i = 0; i < s.size(); i++){
            if(curr >= t) break;
            if(curr < s[i][0]){
                while(!pq.empty() && curr < s[i][0]){
                    curr += pq.top();
                    pq.pop();
                    stops++;
                }
                if(curr < s[i][0]) return -1;
            }
            pq.push(s[i][1]);
        }
        while(!pq.empty() && curr < t){
            curr += pq.top();
            pq.pop();
            stops++; 
        }
        if(curr < t) return -1;
        return stops;
    }
};