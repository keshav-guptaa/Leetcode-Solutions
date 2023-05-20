class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0, j = n-1;
        int ct = 0;
        while(i <= j){
            if(nums[i] == val){
                swap(nums[i], nums[j--]);
                ct++;
            } 
            else i++;
        }
        return n-ct;
    }
};