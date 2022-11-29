class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end()); 
        int ans = 0;
        
        int median = nums[n/2];
        for(int i=0; i<n; i++){
            ans += abs(nums[i] - median);
        }
        
        return ans;
    }
};