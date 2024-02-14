class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        queue<int> pos, neg;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(ans.size() % 2 == 0){
                if(nums[i] > 0) pos.push(nums[i]);
                else neg.push(nums[i]);
                if(pos.size() != 0){
                    ans.push_back(pos.front());
                    pos.pop(); 
                }
            }
            else{
                if(nums[i] < 0) neg.push(nums[i]);
                else pos.push(nums[i]);
                if(neg.size() != 0){
                    ans.push_back(neg.front());
                    neg.pop(); 
                }
            }
        }
        while(ans.size() < n){
            if(ans.size()%2 == 0){
                ans.push_back(pos.front());
                pos.pop();
            }
            else{
                ans.push_back(neg.front());
                neg.pop();
            }
        }
        return ans;
    }
};