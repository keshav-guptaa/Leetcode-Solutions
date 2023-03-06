class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0, j = 0, num = 1;
        while(1){
            if(i < arr.size() && arr[i] == num) i++;
            else j++;
            if(j == k) break;
            num++;
        }
        return num;
    }
};