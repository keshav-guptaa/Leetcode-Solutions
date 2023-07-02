class Solution {
public:
    int f(int mid, vector<int>& nums, int k){
        int ct = 0, n = nums.size();
        for(int i = 0, j = 0; i < n; i++){
            while(j < n && nums[j]-nums[i] <= mid) j++;
            ct += j-i-1;
        }
        return ct >= k;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int s = 0, e = 1000000, mid, ans;
        while(s <= e){
            mid = s + (e-s)/2;
            if(f(mid, nums, k)){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};