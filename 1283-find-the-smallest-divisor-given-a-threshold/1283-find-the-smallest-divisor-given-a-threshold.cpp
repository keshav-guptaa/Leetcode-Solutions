class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int threshold){
        int ct = 0;
        for(int i = 0; i < nums.size(); i++){
            ct += (nums[i]+mid-1)/mid;
        }
        return ct <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1, e = *max_element(nums.begin(), nums.end());
        int mid = s + (e-s)/2;
        int ans;
        while(s <= e){
            if(isPossible(nums, mid, threshold)){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
            mid = s + (e-s)/2;
        }
        return ans;
    }
};