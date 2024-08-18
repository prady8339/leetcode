class Solution {
public:
    int nthUglyNumber(int n) {
       vector<int> arr(1,1);
       int a = 0, b = 0, c = 0;
       while(arr.size() < n){
        int tp = min({
            arr[a] * 2,
            arr[b] * 3,
            arr[c] * 5
        });
        if(tp == arr[a] * 2) a++;
        if(tp == arr[b] * 3) b++;
        if(tp == arr[c] * 5) c++;
        arr.push_back(tp);
       }
       return arr.back();
    }
};