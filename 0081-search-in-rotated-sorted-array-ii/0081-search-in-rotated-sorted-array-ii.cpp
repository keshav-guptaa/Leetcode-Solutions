class Solution {
public:
    
    int binarySearch(vector<int>& nums, int target, int s, int e){
        int mid = s + (e-s)/2;
        
        while(s <= e){
            if(nums[mid] == target){
                return 1;
            }
            else if(nums[mid] == nums[s] && nums[mid] == nums[e]){
                e--;
                s++;
            }
            else if(nums[s] <= nums[mid]){
                if(nums[s] <= target && nums[mid] > target) e = mid-1;
                else s = mid+1;
            }
            else{
                if(nums[mid] < target && nums[e] >= target) s = mid+1;
                else e = mid-1;
            }
            
            mid = s + (e-s)/2;
        }
        return 0;
    }
    
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        return binarySearch(nums, target, 0, n-1);
    }
};