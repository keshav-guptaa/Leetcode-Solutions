class Solution {
public:
    const int mod = 1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size(), mx = -1, ct = 0;
        map<int, int> right;
        for(int i = 0; i < n; i++) right[nums[i]] = i;
        for(int i = 0; i < n; i++){
            mx = max(mx, right[nums[i]]);
            if(mx == i) ct++;
        }
        ct--;
        long long ans = 1;
        while(ct--){
            ans *= 2;
            ans %= mod;
        }
        return int(ans); 
    }
};