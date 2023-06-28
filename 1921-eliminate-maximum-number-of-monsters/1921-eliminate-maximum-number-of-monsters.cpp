class Solution {
public:
    int eliminateMaximum(vector<int>& d, vector<int>& s) {
        int n = d.size();
        vector<int> time(n);
        for(int i = 0; i < n; i++){
            time[i] = (d[i]+s[i]-1)/s[i];
        }
        sort(time.begin(), time.end());
        int ct = 0;
        for(int i = 0; i < n; i++){
            if(i < time[i]) ct++;
            else break;
        }
        return ct;
    }
};