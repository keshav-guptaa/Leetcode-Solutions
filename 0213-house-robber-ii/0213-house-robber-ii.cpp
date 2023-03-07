class Solution {
public:
    int calc(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1; i < n; i++){
            int p = nums[i] + prev2;
            int np = prev;
            int curr = max(p, np);
            prev2 = prev;
            prev = curr;
        }
        return prev;
        
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> temp1, temp2;
        for(int i = 0; i < nums.size(); i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(calc(temp1), calc(temp2));
    }
};