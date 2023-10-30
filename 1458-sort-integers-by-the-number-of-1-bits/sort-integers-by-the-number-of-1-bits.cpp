class Solution {
static bool cmp(int a,int b){
    int ctA = __builtin_popcount(a);
    int ctB = __builtin_popcount(b);
    if(ctA == ctB){
        return a < b;
    }
    return ctA < ctB;
}
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};