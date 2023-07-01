class Solution {
    typedef pair<int, int> pi;
public:
    static bool comp(vector<int>& t1, vector<int>& t2){
        if(t1[1] < t2[1] || (t1[1] == t2[1] && t1[2] < t2[2])) return true;
        return false;
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), comp); 
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        int curr = 0, n = trips.size();
        for(int i = 0; i < n; i++){
            while(!pq.empty() && pq.top().first <= trips[i][1]){
                curr -= pq.top().second;
                pq.pop();
            }
            pq.push({trips[i][2], trips[i][0]});
            curr += trips[i][0];
            cout << curr << " ";
            if(curr > capacity) return false;
        }
        return true;
    }
};