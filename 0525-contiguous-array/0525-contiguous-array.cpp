class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int ans = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += (nums[i] == 0) ? -1 : 1; 
            if(m.find(sum) != m.end()){
                ans = max(ans, i - m[sum]);
            }
            else{
                m[sum] = i;
            }
        }
        return ans;
    }
};