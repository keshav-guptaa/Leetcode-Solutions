class Solution {
public:
    long long f(int x, vector<int>& nums, vector<int>& cost){
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += abs(nums[i]-x)*1LL*cost[i];
        }
        return ans;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int s = 0, e = 1e6, mid;
        long long ans = f(1, nums, cost);
        while(s < e){
            mid = s + (e-s)/2;
            long long x1 = f(mid, nums, cost), x2 = f(mid+1, nums, cost);
            ans = min(x1, x2);
            if(x1 < x2) e = mid;
            else s = mid+1;
        }
        return ans;
    }
};