class Solution {
public:
    bool findSubset(vector<int>& nums, vector<vector<vector<bool>>>& dp, int i, int size, int sum) {
       if (i < 0 || size < 0 || sum < 0)  return false;
       if (dp[i][size][sum] == false) return false;

       if (size == 0) return dp[i][size][sum] = (sum==0);

       // we have 2 choice at element i, take it or leave it
       return dp[i][size][sum] = findSubset(nums, dp, i-1, size-1, sum-nums[i]) 
                               || findSubset(nums, dp, i-1, size, sum);
   }
   bool splitArraySameAverage(vector<int>& nums) {
       int sum = reduce(nums.begin(), nums.end());
       int n = nums.size();  
       // dp[index][subarray_size][subarray_sum]
       vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n+1, vector<bool>(sum+1, true)));

       for (int size = 1; size < n; size++) {
           if (sum*size % n == 0 && findSubset(nums, dp, n-1, size, sum*size/n)) return true;
       }
       return false;
   }
};