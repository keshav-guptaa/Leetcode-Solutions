class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        int mn = INT_MAX;
        for(int i = 0; i < n; i++){
            left[i] = mn;
            mn = min(mn, nums[i]);
        }
        mn = INT_MAX;
        for(int i = n-1; i >= 0; i--){
            right[i] = mn;
            mn = min(mn, nums[i]);
        }
        int ans = INT_MAX;
        // for(int i = 0; i < n; i++){
        //     cout << left[i] << " " << right[i] << endl;
        // }
        for(int i = 1; i < n-1; i++){
            if(left[i] < nums[i] && right[i] < nums[i]){
                ans = min(ans, left[i] + right[i] + nums[i]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};