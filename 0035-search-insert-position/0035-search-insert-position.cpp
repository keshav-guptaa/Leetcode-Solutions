class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        if(nums[0]>target) return 0;
        if(nums[e]<target) return e+1;
        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                if(nums[mid+1]>target) 
                    return mid+1;
                else s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
};