class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++){
            int k = 0;
            while(nums[i] > 0){
                if(nums[i]&1) m[k]++;
                nums[i] >>= 1;
                k++;
            }
        }
        
        int ans = 0;
        for(int i = 0; i <= 32; i++){
            cout << m[i] << " ";
            ans += m[i]*(nums.size()-m[i]);
        }
        return ans;
    }
};