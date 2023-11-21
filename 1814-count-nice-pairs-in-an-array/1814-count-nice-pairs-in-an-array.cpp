class Solution {
public:
    int rev(int n){
        if(n == 0) return 0;
        string s = to_string(n);
        while(s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());
        return stoi(s);
    }
    
    int countNicePairs(vector<int>& nums) {
        int mod = 1e9+7;
        unordered_map<int, int> m;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i], y = rev(nums[i]);
            ans += m[x-y];
            ans %= mod;
            m[x-y]++;
        }
        return ans;
    }
};