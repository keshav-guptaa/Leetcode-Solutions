class Solution {
public:
    int maximum69Number (int num) {
        int c = 0;
        int x = num;
        int z= -1;
        while(x){
            if(x%10 == 6){
                z = c;
            } 
            c++;
            x /= 10;
        }
        if(z != -1) return num + 3*pow(10, z);
        else return num;
    }
};