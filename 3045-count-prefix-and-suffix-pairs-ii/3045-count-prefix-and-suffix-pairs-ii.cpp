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
                //in prefix abc => 31^0 + 31^1 + 31^2, hence 'power' variable helps us.
                prefix = (prefix + (word[i] - 'a' + 1) * power) % mod;
                
                //in suffix the order will be cab from last which is actually in string appear as abc, therefore, we want order 31^2 + 31^1 + 31^0, here, we use the concept of shifting (in decimal multiply by 10), therefore in base 31 (multiply by 31)
                suffix = (suffix * p + (word[j] - 'a' + 1)) % mod;
                power = (power * p) % mod;
                
                if(prefix == suffix && hash.find(prefix) != hash.end())
                    res += hash[prefix];
            }
            
            hash[prefix]++;
            // hash.insert(suffix);
        }
        
        return res;
    }
};