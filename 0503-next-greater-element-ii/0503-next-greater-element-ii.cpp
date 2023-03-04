class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;
        int t = 2;
        while(t--){
            for(int i = n-1; i >= 0; i--){
                if(s.size() == 0) ans[i] = -1;
                else{
                    if(nums[s.top()] > nums[i]) ans[i] = nums[s.top()];
                    else{
                        while(!s.empty() && nums[s.top()] <= nums[i]) s.pop();
                        
                        if(s.empty()) ans[i] = -1;
                        else ans[i] = nums[s.top()];
                    }
                }
                s.push(i);
            }
        }
        return ans;
    }
};