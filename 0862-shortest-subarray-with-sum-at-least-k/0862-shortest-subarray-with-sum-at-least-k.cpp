class Solution {
public:
    //Calc sum, if sum >= k remove elements from start, maintain monotonic increasing deque, put current sum to deque.
    //Iterate the array and calculate sum if it is greater than equal to k then it is a  possible answer now if the current sum is smaller than previous sum stored sum in deque then start removing elements from back because we have to maintain monotonic queue
    int shortestSubarray(vector<int>& nums, int k) {    
        int n = nums.size(), ans = n+1;
        long sum = 0;
        deque<pair<long, int>> d;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum >= k) ans = min(ans, i+1);
            while(d.size() > 0 && sum - d.front().first >= k){
                ans = min(ans, i-d.front().second);
                d.pop_front();
            }
            while(d.size() > 0 && sum <= d.back().first) d.pop_back();
            d.push_back({sum, i});
        }
        return ans == n+1 ? -1 : ans;
    }
};