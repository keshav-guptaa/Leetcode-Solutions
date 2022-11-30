class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end());
        int e = 0;
        for(int i = 0; i < weights.size(); i++){
            e += weights[i];
        }
        int mid = -1;
        int curr, req;
        while(s < e){
            mid = s + (e-s) / 2;
            req = 1; curr = 0;
            for(int i = 0; i < weights.size() && req <= days; curr += weights[i++]){
                if(curr + weights[i] > mid){
                    curr = 0;
                    req++;
                }
            }
            if(req > days) s = mid + 1;
            else e = mid;
        }
        return s;
    }
};