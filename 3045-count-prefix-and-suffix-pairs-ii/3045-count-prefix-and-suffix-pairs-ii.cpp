typedef long long ll;
class Solution { 
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        const int p = 31, mod = 1e9 + 9;
        ll res = 0;
        unordered_map<ll, int> hash;
        
        for(string word : words) {
            ll prefix = 0, suffix = 0;
            ll power = 1;
            
            int n = word.size();
            
            for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
                prefix = (prefix + (word[i] - 'a' + 1) * power) % mod;
                power = (power * p) % mod;
                
                suffix = (suffix * p + (word[j] - 'a' + 1)) % mod;
                
                if(prefix == suffix && hash.find(prefix) != hash.end())
                    res += hash[prefix];
            }
            
            hash[prefix]++;
            // hash.insert(suffix);
        }
        
        return res;
    }
};