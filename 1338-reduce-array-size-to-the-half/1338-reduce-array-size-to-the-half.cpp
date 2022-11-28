class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> v;
        int count = 1;
        int n = arr.size();
        for(int i = 0; i < n-1; i++){
            if(arr[i] == arr[i+1]) count++;
            else{
                v.push_back(count);
                count = 1;
            } 
        }
        if(count != 1) v.push_back(count);
        sort(v.begin(), v.end());
        int ans = 0;
        count = 0;
        for(int i = v.size()-1; i >= 0 && count < n/2; i--){
            count += v[i];
            ans++;
        }
        return ans;
    }
};