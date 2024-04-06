class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {    
        int n = nums.size(), ans = n+1;
        long sum = 0;
        deque<pair<long, int>> d;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum >= k) ans = min(ans, i+1);
            
            while(d.size() > 0 && sum <= d.back().first) d.pop_back();
            
            while(d.size() > 0 && sum - d.front().first >= k){
                ans = min(ans, i-d.front().second);
                d.pop_front();
            }
            d.push_back({sum, i});
        }
        return ans == n+1 ? -1 : ans;
    }
};