class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size(), count = 1, dup=1;
        while(j < n){
            if(nums[i] != nums[j]){
                i++;
                swap(nums[i],nums[j]);
                count++;
                dup = 1;
            }
            else{
                if(dup == 1){
                    i++;
                    swap(nums[i],nums[j]);
                    count++;
                    dup++;
                }
            }
            j++;
        }
        return count;
    }
};