class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int x = f.size();
        vector<int> v(x+2, 0);
        for(int i = 0; i < x; i++){
            v[i+1] = f[i];
        }
        for(int i = 1; i <= x; i++){
            if(v[i] == 0 && v[i-1] == 0 && v[i+1] == 0){
                v[i] = 1;
                n--;
            }
        }
        return  n <= 0;
    }
};