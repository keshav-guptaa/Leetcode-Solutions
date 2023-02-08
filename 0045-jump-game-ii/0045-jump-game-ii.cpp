class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> pf(n);
        int prev = 0;
        for(int i = 0; i < n; i++){
            prev = max(prev, i + nums[i]);
            pf[i] = prev;
        }
        int jump = 0;
        int curr = 0;
        while(curr < n-1){
            jump++;
            curr = pf[curr];
        }
        return jump;
    }
};