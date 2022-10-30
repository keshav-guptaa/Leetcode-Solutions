class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        if(nums[0] > nums[n-1]){
            while(s <= e){
                
                if(nums[mid] > nums[mid+1]) return nums[mid+1];
                if(nums[mid] < nums[mid-1]) return nums[mid];
                
                
                if(nums[mid] > nums[0]) s = mid + 1;
                else e = mid - 1;
                mid = s + (e-s)/2;
            }
        }
        return nums[s];
    }
};