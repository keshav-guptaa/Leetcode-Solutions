class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size(), ct = 1;
        while(j < n){
            if(nums[i] != nums[j]){
                i++;
                swap(nums[i],nums[j]);
                ct++;
            }
            j++;
        }
        return ct;;
    }
};