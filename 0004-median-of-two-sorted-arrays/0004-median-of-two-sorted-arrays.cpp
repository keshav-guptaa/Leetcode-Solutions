class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2){
        int i = 0, j = 0;
        int n = n1.size(), m = n2.size();
        vector<int> v;
        while(i < n && j < m){
            if(n1[i] < n2[j]){
                v.push_back(n1[i++]);
            }
            else v.push_back(n2[j++]);
        }
        
        while(i < n) v.push_back(n1[i++]);
        while(j < m) v.push_back(n2[j++]);
        
        int size = n+m;
        return size&1 ? v[size/2]: (v[size/2]+v[size/2 - 1])/2.0 ;
        
    }
};