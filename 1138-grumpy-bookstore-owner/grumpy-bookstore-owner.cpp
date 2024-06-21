class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       int sat = 0;
       int n = customers.size();
       for(int i = 0 ; i < n ; i++){
            if(grumpy[i] == 0){
                sat += customers[i];
            }
       } 
       int l = 0, r = 0;
       int ans = 0;
       int addOn = 0;
       while(r < minutes){
        if(grumpy[r] == 1)
            addOn += customers[r];
        r++;
       }
        ans = max(addOn, ans);
       while(r < n){
        if(grumpy[r] == 1)
            addOn += customers[r];
        if(grumpy[l] == 1)
            addOn -= customers[l];
        l++;
        r++;
        ans = max(addOn, ans);
       }

       return ans + sat;
    }
};