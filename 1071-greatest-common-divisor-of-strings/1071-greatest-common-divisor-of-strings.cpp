class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        return (s1 + s2 == s2 + s1)  ? s1.substr(0, gcd(s1.length(), s2.length())) : "";
    }
};