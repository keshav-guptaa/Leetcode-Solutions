class Solution {
public:
    string validIPAddress(string IP) {
        if(count(IP.begin(), IP.end(), '.') == 3){
            if(IP[IP.length()-1] == '.') return "Neither";
            stringstream ss(IP);
            string token;
            while(getline(ss, token, '.')){
                if(token.length() == 0 || token.length() > 3) return "Neither";
                if(token[0] == '0' && token.length() != 1) return "Neither";
                for(auto& it: token) if(!isdigit(it)) return "Neither";
                if(stoi(token) > 255) return "Neither";
            }
            return "IPv4";
        }
        else if(count(IP.begin(), IP.end(), ':') == 7){
            if(IP[IP.length()-1] == ':') return "Neither";
            stringstream ss(IP);
            string token;
            while(getline(ss, token, ':')){
                if(token.length() == 0 || token.length() > 4) return "Neither";
                for(auto& it: token){
                    if((it >= '0' && it <= '9') || (it >= 'a' && it <= 'f') || (it >= 'A' && it <= 'F')) continue;
                    else return "Neither";
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};