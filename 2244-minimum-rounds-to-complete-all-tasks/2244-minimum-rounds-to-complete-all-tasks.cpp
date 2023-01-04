class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> count;
        int n = tasks.size();
        for(int i = 0; i < n; i++){
            count[tasks[i]]++;
        }
        int ans = 0;
        for(auto x: count){
            if(x.second%3 == 0) ans += x.second/3;
            else if(x.second%3 == 2) ans += x.second/3 + 1;
            else{
                if(x.second == 1){
                    ans = -1;
                    break;
                }
                else{
                    ans++;
                    x.second -= 2;
                    ans += x.second/3 + 1;
                }
            }
        }
        return ans;
    }
};