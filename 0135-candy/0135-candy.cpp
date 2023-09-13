class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();
        vector<int> candi(n,1);
        for(int i = 1 ; i < n ; i++){
          if(rat[i]>rat[i-1]) candi[i] = 1+candi[i-1];
        }
        for(int i = n-2 ; i >=0 ; i--){
          if(rat[i]>rat[i+1]) candi[i] = max(candi[i],1+candi[i+1]);
        }
        int sum = 0;
        for(int i = 0 ; i < n ; i++) sum+=candi[i];
        
        return sum;
    }
};