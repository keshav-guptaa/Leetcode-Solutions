class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int n1, n2, ct1 = 0, ct2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == n1) ct1++;
            else if(nums[i] == n2) ct2++;
            else if(ct1 == 0){
                n1 = nums[i];
                ct1 = 1;
            }
            else if(ct2 == 0){
                n2 = nums[i];
                ct2 = 1;
            }
            else{
                ct1--;
                ct2--;
            }
        }
        ct1 = 0, ct2 = 0;
        for(auto it: nums){
            if(it == n1) ct1++;
            if(it == n2) ct2++;
        }
        if(ct1 > n/3 && ct2 > n/3) return {n1, n2};
        else if(ct1 > n/3) return {n1};
        else if(ct2 > n/3) return {n2};
        return {};
    }
};