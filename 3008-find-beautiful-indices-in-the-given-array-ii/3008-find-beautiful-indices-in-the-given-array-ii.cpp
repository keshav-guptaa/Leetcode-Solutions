#define print(x)           for(int i=0; i<x.size(); i++) cout << x[i] << " "; cout<<endl;
class Solution {
public:
    vector<int> calcLPS(string& pattern){
        int n = pattern.length();
        vector<int> lps(n, 0);
        
        int i = 1, len = 0;
        while(i < n){
            if(pattern[i] == pattern[len]) lps[i++] = ++len;
            else{
                if(len == 0) i++;
                else len = lps[len-1];
            }
        }
        return lps;
    }
    
    vector<int> findAll(string& text, string& pattern){
        vector<int> idx;
        vector<int> lps = calcLPS(pattern);
        //print(lps);
        int i = 0, j = 0;
        while(i < text.length()){
            if(text[i] == pattern[j]){
                i++;
                j++;
            } 
            else{
                if(j != 0) j = lps[j-1];
                else i++;
            }
            
            if(j == pattern.length()){
                idx.push_back(i-j);
                j = lps[j-1];
            }
        }
        return idx;
    }
    
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> i1 = findAll(s, a);
        vector<int> i2 = findAll(s, b);
        //print(i1); print(i2);
        vector<int> ans;
        for(int i = 0; i < i1.size(); i++){
            int lb = lower_bound(i2.begin(), i2.end(), i1[i]-k) - i2.begin();
            int ub = upper_bound(i2.begin(), i2.end(), i1[i]+k) - i2.begin();
            if(ub > lb) ans.push_back(i1[i]);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> calculateLPS(string& pattern) {
//     vector<int> lps(pattern.size(), 0);
//     int len = 0;
//     int i = 1;

//     while (i < pattern.size()) {
//         if (pattern[i] == pattern[len]) {
//             len++;
//             lps[i] = len;
//             i++;
//         } else {
//             if (len != 0) {
//                 len = lps[len - 1];
//             } else {
//                 lps[i] = 0;
//                 i++;
//             }
//         }
//     }

//     return lps;
// }

// vector<int> findAll(string& text, string& pattern) {
//     vector<int> occurrences;
//     vector<int> lps = calculateLPS(pattern);
//     print(lps);
//     int i = 0, j = 0;

//     while (i < text.size()) {
//         if (pattern[j] == text[i]) {
//             i++;
//             j++;
//         }

//         if (j == pattern.size()) {
//             occurrences.push_back(i - j);
//             j = lps[j - 1];
//         } else if (i < text.size() && pattern[j] != text[i]) {
//             if (j != 0) {
//                 j = lps[j - 1];
//             } else {
//                 i++;
//             }
//         }
//     }

//     return occurrences;
// }
// vector<int> helper(vector<int>& a, vector<int>& b, int k) {
//     vector<int> result;

//     // Iterate over each element in array a
//     for (int i = 0; i < a.size(); ++i) {
//         // Binary search to find the range of elements in array b satisfying the condition
//         int low = lower_bound(b.begin(), b.end(), a[i] - k) - b.begin();
//         int high = upper_bound(b.begin(), b.end(), a[i] + k) - b.begin();

//         // Check if there are elements in the range
//         if (low < high) {
//             result.push_back(a[i]);
//         }
//     }

//     return result;
// }
//     vector<int> beautifulIndices(string s, string a, string b, int k) {
//         vector<int>posA=findAll(s,a);
//         vector<int>posB=findAll(s,b);
//         print(posA); print(posB);
//         vector<int>ans=helper(posA,posB,k);
//         return ans;
        
//     }
// };