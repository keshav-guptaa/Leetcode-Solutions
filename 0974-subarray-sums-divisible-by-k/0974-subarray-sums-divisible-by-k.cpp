class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] += nums[i-1];
        }
        map<int, int> m;
        int ans = 0;
        for(int i = 0; i < n; i++){
            //cout << nums[i] << " ";
            
            nums[i] %= k;
            if(nums[i] < 0){
                nums[i] += k;
            }
            //cout << nums[i] << " ";
            ans += m[nums[i]];
            //cout << ans << endl;
            m[nums[i]]++;
        }
        ans += m[0];
        return ans;
    }
};