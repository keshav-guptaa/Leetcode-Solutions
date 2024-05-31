class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(auto& it: nums) xorr ^= it;
        int i = 0;
        while(!(xorr & (1 << i))) i++;
        int nxorr = 0;
        for(auto& it: nums){
            if(it & (1 << i)) nxorr ^= it;
        }
        return {nxorr, (nxorr^xorr)};
    }
};