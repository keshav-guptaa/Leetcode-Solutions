class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        int ans = -1;
        while(i < n && j < m){
            if(nums1[i] == nums2[j]){
                ans = nums1[i];
                break;
            }
            else if(nums1[i] > nums2[j]) j++;
            else i++;
        }
        return ans;
    }
};