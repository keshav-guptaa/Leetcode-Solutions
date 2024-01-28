class Solution {
public:
    long long flowerGame(int n, int m) {
        int ne = n/2, no = (n+1)/2;
        int me = m/2, mo = (m+1)/2;
        return ne*1LL*mo + no*1LL*me;
    }
};