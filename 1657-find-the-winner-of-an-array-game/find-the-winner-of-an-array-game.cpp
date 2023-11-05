class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int prev = arr[0];
        int count = 0;
        for(int i = 1 ; i < n ; i++){
           if(prev > arr[i]){
               count++;
           }else{
               prev = arr[i];
               count = 1;
           }
           if(count >= k) return prev;
        }
        return prev;
    }
};