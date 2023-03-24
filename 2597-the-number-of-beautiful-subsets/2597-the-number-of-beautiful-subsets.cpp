class Solution {
public:
    
        
    int ans=0;
    void recur(vector<int>&curr,vector<int>&nums,int k,int ind){
        if(ind==nums.size()){
            if(curr.size())ans++;
            return;
        }
        if(binary_search(curr.begin(),curr.end(),nums[ind]-k)){
            recur(curr,nums,k,ind+1);
            return;
        }
        recur(curr,nums,k,ind+1);
        curr.push_back(nums[ind]);
        recur(curr,nums,k,ind+1);
        curr.pop_back();
    }
    
    
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        recur(curr,nums,k,0);
        return ans;
    }
        
        
    
};