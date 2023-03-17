class Solution {
private: 
    int binarySearch(vector<int>& nums, int target){
    int s=0;
    int e=nums.size()-1;
    int mid = s+(e-s)/2;
    while(s<=e){
        
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) e = mid-1;
        else s = mid+1;
        
        mid = s+(e-s)/2;
    }
    return -1;
}
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        /*
        vector<int> ans;
        int l = numbers.size();
        int sec;
        for(int i=0; i<l; i++){
           sec = target - numbers[i];
           sec = binarySearch(numbers, sec);
           if((sec != -1) && (i != sec)){
               ans.push_back(i+1);
               ans.push_back(sec+1);
               break;
           }
        }
        sort(ans.begin(),ans.end());
        return ans;
        */
        int n = nums.size();
        int s = 0, e = n-1;
        while(s < e){
            if(nums[s] + nums[e] == t) break;
            else if(nums[s] + nums[e] > t) e--;
            else s++;
        }
        return {s+1, e+1};
    }
};