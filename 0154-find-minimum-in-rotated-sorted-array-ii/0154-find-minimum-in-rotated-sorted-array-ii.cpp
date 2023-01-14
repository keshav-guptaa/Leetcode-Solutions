class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        int mid;
        while(s < e){
            mid = s + (e-s)/2;
            if(nums[mid] == nums[s] && nums[mid] == nums[e]){
                s++;
                e--;
            }
            else if(nums[mid] <= nums[e]) e = mid;
            else if(nums[mid] >= nums[s]) s = mid+1;
        }
        return nums[s];
    }
};