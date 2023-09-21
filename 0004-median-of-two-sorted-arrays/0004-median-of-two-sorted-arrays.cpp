class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2){
        int n = n1.size(), m = n2.size();
        if(n > m) return findMedianSortedArrays(n2, n1);
        int total = n+m, s = 0, e = n;
        double ans = 0.0;
        int i, j;
        while(s <= e){
            //In case of total elements are odd, then, left partition has more elements.
            i = s + (e-s)/2; // representing 1st element of right partition in n1.
            j = (total+1)/2 - i; // representing 1st element of right partition in n2.
            
            int l1 = (i > 0) ? n1[i - 1] : INT_MIN;
            int r1 = (i < n) ? n1[i] : INT_MAX;
            int l2 = (j > 0) ? n2[j - 1] : INT_MIN;
            int r2 = (j < m) ? n2[j] : INT_MAX;
            
            //Partition is correct.
            if(l1 <= r2 && l2 <= r1){
                //For odd case left partition has more elements, hence, it contains answer.
                if(total&1){
                    ans = max(l1, l2);
                }
                //
                else{
                    ans = (max(l1, l2) + min(r1, r2))/2.0;
                }
                break;
            }
            //Partition is wrong.
            else if(l1 > r2) e = i-1;
            else s = i+1;
        }
        
        return ans;
        
    }
};