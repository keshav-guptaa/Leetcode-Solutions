class Solution {
public:
    static bool cmp(string &a,string &b)
    {
        if(a.size()==b.size())
        {
            return a<b;
        }
        return a.size()<b.size();
    }
    string kthLargestNumber(vector<string>& nums, int k) 
    {
        sort(nums.begin(), nums.end(), [](string &a, string &b){
            if(a.length() == b.length()) return a < b;
            return a.length() < b.length();
        });
        int n = nums.size();
        return nums[n-k];
    }
};