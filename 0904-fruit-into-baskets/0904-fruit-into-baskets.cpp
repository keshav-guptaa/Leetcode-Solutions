class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> m;
        int i = 0, j = 0, n = fruits.size();
        int ct = 0;
        int ans = 0;
        while(j < n){
            m[fruits[j]]++;
            ct++;
            while(m.size() > 2){
                m[fruits[i]]--;
                ct--;
                if(m[fruits[i]] == 0) m.erase(fruits[i]);
                i++;
            }
            ans = max(ans, ct);
            j++;
        }
        return ans;
    }
};