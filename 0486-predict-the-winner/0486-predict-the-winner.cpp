class Solution {
public:
    int f(int idx1, int idx2, vector<int>& nums){
        if(idx1 > idx2) return 0;
        if(idx1 == idx2) return nums[idx1];
        
        int left = nums[idx1] + min(f(idx1+2, idx2, nums), f(idx1+1, idx2-1, nums));
        int right = nums[idx2] + min(f(idx1+1, idx2-1, nums), f(idx1, idx2-2, nums));
        return max(left, right);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        int x = f(0, n-1, nums);
        //cout << x << endl;
        return x >= sum-x;
    }
};