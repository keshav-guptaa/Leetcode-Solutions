class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int i = 1;
        while(n - i >= 0){
            n -= i;
            i++;
        }
        return --i;
    }
};