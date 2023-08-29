class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int idx = -1;
        int mini = INT_MAX;
        int p = 0;
        for(int i = 0 ; i < n ; i++){
            if(customers[i]=='Y') p++;
        }
        for(int i = 0 ; i < n ;i++){
            if(p < mini){
                mini = p;
                idx = i;
            }

            if(customers[i]=='Y') p--;
            else p++;
            
        }

        if(p < mini){
                mini = p;
                idx = n;
        }
        
        return idx;
    }
};