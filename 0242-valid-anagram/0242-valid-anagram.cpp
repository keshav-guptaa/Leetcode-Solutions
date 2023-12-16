class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26];
        memset(arr,0,sizeof(arr));
        for(int i=0; i<s.length(); i++){
            arr[s[i]-'a']++;
        }
        for(int i=0; i<t.length(); i++){
            arr[t[i]-'a']--;
        }
        
        return count(arr,arr+26,0) == 26 && s.length() == t.length();
    }
};