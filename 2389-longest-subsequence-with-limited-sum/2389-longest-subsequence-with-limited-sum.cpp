class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> pf(nums.size());
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            pf[i] = sum;
        }
        vector<int> ans(queries.size());
        int j = 0;
        for(int i = 0; i < queries.size(); i++){
            int s = 0; 
            int e = pf.size() - 1;
            int temp = -1;
            int mid = s + (e-s)/2;
            while(s <= e){
                mid = s + (e-s)/2;
                if(pf[mid] <= queries[i]){
                    temp = mid;
                    s = mid + 1;
                }
                else e = mid - 1;
            }
            ans[i] = temp + 1;
        }
        return ans;
    }
};