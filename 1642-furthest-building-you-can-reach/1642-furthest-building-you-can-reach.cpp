class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int> pq;
        for(int i = 0; i < h.size()-1; i++){
            int diff = h[i+1]-h[i];
            if(diff > 0) pq.push(-diff);
            if(pq.size() > ladders){
                bricks += pq.top();
                pq.pop();
            }
            if(bricks < 0) return i;
        }
        return h.size()-1;
    }
};