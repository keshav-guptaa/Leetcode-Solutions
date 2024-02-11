#define print(x) for(int i=0; i<x.size(); i++) cout << x[i] << " "; cout<<endl;
class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> len;
        vector<int> v(26, 0);
        for(int i = 0; i < words.size(); i++){
            len.push_back(words[i].length());
            for(auto &it: words[i]){
                v[it-'a']++;
            }
        }
        sort(len.begin(), len.end());
        int odd = 0, even = 0, ans = 0;
        for(int i = 0; i < 26; i++){
            if(v[i]&1){
                v[i]--;
                odd++;
            }
            even += v[i];
        }
        //print(len);
       
        for(int i = 0; i < len.size(); i++){
            if(len[i]&1){
                len[i]--;
                if(odd > 0){
                    if(even >= len[i]){
                        even -= len[i];
                        odd--;
                        ans++;
                    }
                }
                else{
                    if(even-2 >= len[i]){
                        even -= len[i];
                        even -= 2;
                        odd++;
                        ans++;
                    }
                }
            }
            else{
                if(len[i] > even) break;
                else{
                    even -= len[i];
                    ans++;
                } 
            }
        }
        return ans;
    }
};