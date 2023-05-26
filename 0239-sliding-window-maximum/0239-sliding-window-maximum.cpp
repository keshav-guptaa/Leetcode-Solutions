class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();
        vector<int> ans(n-k+1);
        deque<int> q;
        while(j < n){
            while(q.size() > 0 && q.back() < nums[j]) q.pop_back();
            q.push_back(nums[j]);
            if(j-i+1 == k){
                ans[i] = q.front();
                if(nums[i++] == q.front()) q.pop_front();
            } 
            j++;
        }
        return ans;
    }
};