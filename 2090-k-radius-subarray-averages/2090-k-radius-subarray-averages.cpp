class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if(2*k >= n) return ans;
        long sum = 0, i = 0, j = 0;  
        for(; i <= 2*k; i++) sum += nums[i];
        int size = 2*k+1;
        //cout << sum << endl;
        while(i < n){
            //cout << sum << endl;
            ans[k++] = sum/size;
            sum -= nums[j++];
            sum += nums[i++];
        }
        ans[k++] = sum/size;
        return ans;
    }
};