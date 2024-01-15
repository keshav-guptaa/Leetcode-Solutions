class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1), dp2(n, 1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp1[i] = max(dp1[i], 1 + dp1[j]);
                }
            }
        }
        
        reverse(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp2[i] = max(dp2[i], 1 + dp2[j]);
                }
            }
        }
        
        int ans = 0, i = 0, j = n-1;
        while(i < n){
            if(dp1[i] != 1 && dp2[j] != 1) ans = max(ans, dp1[i]+dp2[j]);
            i++; j--;
        }
        //cout << ans << endl;
        return n-ans+1;
    }
};