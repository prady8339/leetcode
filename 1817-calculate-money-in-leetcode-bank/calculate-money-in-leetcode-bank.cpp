class Solution {
public:
    int totalMoney(int n) {
        
        int i = 1;
        int addon = 0;
        int counter = 1;
        int sum = 0; 
        while(i <= n){
            sum += counter;
            if(i % 7 == 0){
                addon++;
                counter = addon;
            }
            counter++;
            i++;
        }
        return sum;
    }
};