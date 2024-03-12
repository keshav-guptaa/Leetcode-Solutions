class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> in;
    unordered_map<string, pair<int, int>> m;
    
    UndergroundSystem() {
        in.clear();
        m.clear();
    }
    
    void checkIn(int id, string s, int t) {
        in[id] = {s, t};
    }
    
    void checkOut(int id, string s, int t) {
            auto it = in[id];
            string st = it.first+"_"+s;
            int t0 = t-it.second; 
            m[st].first += t0;
            m[st].second++;
            in.erase(id);
    }
    
    double getAverageTime(string s, string e) {
        string st = s +"_"+e;
        return double(m[st].first)/m[st].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */