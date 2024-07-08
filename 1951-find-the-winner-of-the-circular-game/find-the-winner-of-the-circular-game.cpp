class Solution {
public:
    int findTheWinner(int n, int k) {
       vector<int> arr(n, 0);
       for(int i = 0 ; i < n ; i++){
        arr[i] = i + 1;
       } 
       int index = 0;
        while (arr.size() > 1) {
            index = (index + k - 1) % arr.size(); 
            arr.erase(arr.begin() + index); 
        }

       return arr[0];
    }
};