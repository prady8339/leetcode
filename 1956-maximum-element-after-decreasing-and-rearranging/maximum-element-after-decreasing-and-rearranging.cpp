class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int prev = 1;
        arr[0] = prev;
        for(int i = 1 ; i < arr.size() ; i++){
            if(abs(arr[i]-prev)>1){
                arr[i] = prev+1;
            }
            prev = arr[i];
        }
        return arr[arr.size()-1];
    }
};