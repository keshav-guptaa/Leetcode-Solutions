class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        int i = 0;
        for(auto x: nums){
            i ^= x;
            ans += m[i]++;
        }
        return ans;
    }
};