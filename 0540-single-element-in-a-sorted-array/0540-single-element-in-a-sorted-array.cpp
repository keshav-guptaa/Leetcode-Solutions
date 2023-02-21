class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 1, e = n-2;
        int mid = s + (e-s)/2;
        if(n == 1) return nums[0];
        while(s <= e){
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            else if(nums[mid] == nums[mid-1] && (mid&1)){
                s = mid+1;
            }
            else if(nums[mid] == nums[mid+1] && !(mid&1)){
                s = mid+1;
            }
            else e = mid-1;
            mid = s + (e-s)/2;
        }
        if(s == n-1) return nums[s];
        if(e == 0) return nums[e];
        return -1;
    }
};