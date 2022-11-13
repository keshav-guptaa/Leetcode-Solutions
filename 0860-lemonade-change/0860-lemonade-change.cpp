class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        bool f = 1;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5) five++;
            else if(bills[i] == 10){
                if(five == 0){
                    f = 0;
                    break;
                }
                five--;
                ten++;
            } 
            else{
                if(five > 0 && ten > 0){
                    five--;
                    ten--;
                }
                else if(five >= 3){
                    five -= 3;
                } 
                else{
                    f = 0;
                    break;
                }
            }
        }
        return f;
    }
};