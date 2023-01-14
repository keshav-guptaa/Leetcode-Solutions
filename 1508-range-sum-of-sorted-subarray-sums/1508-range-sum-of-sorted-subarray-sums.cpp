class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        vector<int> sum;
        for(int i = 0; i < n; i++){
            int s = 0;
            for(int j = i; j < n; j++){
                s += nums[j];
                sum.push_back(s);
            }
        }
        sort(sum.begin(), sum.end());
        //for(auto x: sum) cout << x << " ";
        long long ans = 0;
        for(int i = l-1; i < r; i++){
            ans += sum[i];
        }
        return int(ans%1000000007);
    }
};