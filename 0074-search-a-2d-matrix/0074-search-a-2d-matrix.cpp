class Solution {
public:

    bool searchMatrix(vector<vector<int>>& arr, int x) {
        int n=arr.size();
        int m=arr[0].size();
        int s = 0, e = n*m-1, mid;
        while(s <= e){
            mid = s + (e-s)/2;
            if(arr[mid/m][mid%m] == x) return 1;
            else if(arr[mid/m][mid%m] > x) e = mid - 1;
            else s = mid + 1;
        }
        return 0;
    }
};