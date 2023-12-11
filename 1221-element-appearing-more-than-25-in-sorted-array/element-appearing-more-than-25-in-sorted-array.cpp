class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int prev = arr[0];
        int count = 1;
        int n = arr.size();
        for(int i = 1 ;i < n ;i++){
            if(prev!=arr[i]){
                count = 1;
            }else{
                count++;
            }
            if(count > n / 4) return arr[i];
            prev = arr[i];
        }
        return arr[0];
    }
};