class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n - 1;
        int area = 0;
        int lmax = v[l],rmax = v[r];
        while( l <= r){
            if(v[l] <= v[r]){
                if(v[l]>=lmax) lmax=v[l];
                else area += lmax-v[l];
                l++;
            }else{
                if(v[r]>=rmax) rmax = v[r];
                else area += rmax - v[r]; 
                r--;
            }
        }
        return area;
    }
};