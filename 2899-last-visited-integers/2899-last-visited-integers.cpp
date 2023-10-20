class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> ans, nums;
        int idx = -1;
        for(auto &it: words){
            if(it != "prev"){
                nums.push_back(stoi(it));
                idx = nums.size()-1;
            }
            else{
                if(idx >= 0) ans.push_back(nums[idx--]);
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};