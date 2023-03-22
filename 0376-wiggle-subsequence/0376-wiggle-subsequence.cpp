class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int f = 0, ct1 = 0, ct2 = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1] && f == 0){
                f = 1-f;
                ct1++;
            }
            else if(nums[i+1] > nums[i] && f == 1){
                f = 1-f;
                ct1++;
            } 
        }
        f = 1;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1] && f == 0){
                f = 1-f;
                ct2++;
            }
            else if(nums[i+1] > nums[i] && f == 1){
                f = 1-f;
                ct2++;
            } 
        }
        return max(ct1+1, ct2+1);
    }
};