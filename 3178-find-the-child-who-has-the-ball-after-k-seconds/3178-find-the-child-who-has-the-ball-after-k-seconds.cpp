class Solution {
public:
    int numberOfChild(int n, int k) {
        bool f = 1;
        int i = 0;
        while(k--){
            if(f) i++;
            else i--;
            if(i == n-1) f = 0;
            if(i == 0) f = 1;
        }
        return i;
    }
};