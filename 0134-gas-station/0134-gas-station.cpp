class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0, curr = 0, ans = 0;
        for(int i = 0; i < n; i++){
            int diff = gas[i] - cost[i];
            sum += diff;
            curr += diff;
            if(curr < 0){
                curr = 0;
                ans = i+1;
            }
        }
        if(sum >= 0) return ans;
        return -1;
    }
};