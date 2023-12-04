class Solution {
public:

    
    int minimumAddedCoins(vector<int>& c, int target) {
        int res = 0, obtain = 0;
        sort(begin(c), end(c));
        for (int i = 0; i < c.size() && obtain < target; ++i) {
            while (obtain + 1 < c[i]) {
                obtain += obtain + 1;
                ++res;
            }
            obtain += c[i];
            cout<<obtain << endl;
        }
        while (obtain < target) {
            cout<<obtain << endl;
            obtain += obtain + 1;
            ++res;
        }    
        return res;
    }
};