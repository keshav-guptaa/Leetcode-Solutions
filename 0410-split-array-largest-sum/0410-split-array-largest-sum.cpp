class Solution {
public:
    int f(int mid, vector<int>& nums, int k){
        int req = 1, ct = 0;
        for(auto &it: nums){
            ct += it;
            if(ct > mid){
                ct = it;
                req++;
            }
        }
        return req <= k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int s = 0, e = 0, mid, ans;
        for(auto &it: nums){
            e += it;
            s = max(s, it);
        }
        while(s <= e){
            mid = s + (e-s)/2;
            if(f(mid, nums, k)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};