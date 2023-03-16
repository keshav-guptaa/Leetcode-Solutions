class Solution {
public:
    int reachNumber(int tar) {
        tar = abs(tar);
        int k = 0;
        while(tar > 0){
            tar -= ++k;
        }
        return (tar&1) ? k+1 + k%2:k;
    }
};