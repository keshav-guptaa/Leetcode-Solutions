class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int sum = nums[i] + nums[j];
                int dif = abs(nums[i] - nums[j]);
                auto it1 = lower_bound(nums.begin()+j+1, nums.end(), sum)                            - nums.begin();
                //if(it2 == n) it2 = 0;
                
                //if(it1 == n) it1--;
                //if(i >= it2 && i <= it1) ans--;
                //if(j >= it2 && j <= it1) ans--;
                //cout << it1 << " " << it2 << " " << i << " " << j << endl;
                ans += (it1 - j - 1);
            }
        }
        return ans;
    }
};