class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int n = 1;
        int i = 0;
        while(i < 32){
            if(find(nums.begin(), nums.end(), n) == nums.end()) break;
            n <<= 1;
            i++;
        }
        return n;
    }
};