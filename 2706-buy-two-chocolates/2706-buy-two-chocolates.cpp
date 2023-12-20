#define endl               "\n"
#define ci                 const int
#define pb                 push_back
#define yes                cout<<"YES"<<endl
#define no                 cout<<"NO"<<endl
#define ff(i,a,b,x)        for(int i=a; i<=b; i+=x)
#define fb(i,a,b,x)        for(int i=a; i>=b; i-=x)
#define all(x)             (x).begin(), (x).end()
#define ub                 upper_bound
#define lb                 lower_bound
#define csb                __builtin_popcount
#define neg                cout<<-1<<endl
#define in(x)              for(int i=0; i<x.size(); i++) cin >> x[i];
#define print(x)           for(int i=0; i<x.size(); i++) cout << x[i] << " "; cout<<endl;
#define sqrt(x)            sqrtl(x)
#define vi                 vector<int> 

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(all(prices));
        return (money >= prices[0]+prices[1]) ? money-prices[0]-prices[1] : money;
    }
};