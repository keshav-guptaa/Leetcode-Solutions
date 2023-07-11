class StockSpanner {
public:
    stack<pair<int, int>> st;
    int ct;
    StockSpanner() {
        ct = 0;
    }
    
    int next(int price) {
        ct++;
        while(!st.empty() && st.top().first <= price) st.pop();
        if(st.empty()){
            st.push({price, ct});
            return ct;;
        }
        int x = ct-st.top().second;
        st.push({price, ct});
        return x;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */