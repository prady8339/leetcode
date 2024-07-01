class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
       int oc = 0;
       for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] % 2 == 1){
            oc++;
            if(oc >= 3) return true;
        }else{
            oc = 0;
        }
       }
       return false;
    }
};