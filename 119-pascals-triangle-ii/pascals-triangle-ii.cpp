class Solution {
public:
    vector<int> getRow(int n) {
        if(n==0) return {1};

        vector<int> arr;
        arr.push_back(1);
        for(int i = 1 ; i <= n ; i++){
            vector<int> next(i+1,0);
            for(int j = 0 ; j < i+1 ; j++){
                if(j-1<0)
                next[j] = arr[j];
                else if(j>=i)
                next[j] = arr[j-1];
                else 
                next[j] = arr[j-1] + arr[j];
            }
            arr = next;
        }
        return arr;
    }
};