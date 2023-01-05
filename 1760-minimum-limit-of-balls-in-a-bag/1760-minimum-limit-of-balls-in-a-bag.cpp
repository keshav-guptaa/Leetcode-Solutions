class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int maxOperations){
        int req = 0;
        for(int x: nums){
            int ops = x/mid;
            if(x % mid == 0) ops--;
            req += ops;
        }
        return req <= maxOperations;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int s = 1, e = *max_element(nums.begin(), nums.end());
        int mid = s + (e-s)/2, ans;
        //int penalty = e;
        while(s <= e){
            if(isPossible(nums, mid, maxOperations)){
                e = mid-1;
                ans = mid;
                //penalty = mid;
            }
            else s = mid+1;
            mid = s + (e-s)/2;
        }
        return ans;
    }
};