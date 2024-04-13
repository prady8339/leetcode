class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int sum = 0;
        int lmax = h[0], rmax = h[r];
        while(l < r){
            
            if(h[l] < h[r]){
                if(lmax - h[l] > 0)
                    sum += lmax - h[l];
                l++;
            }else{
                if(rmax - h[r] > 0)
                    sum += rmax - h[r];
                r--;
            }
              lmax = max(h[l], lmax);
              rmax = max(h[r], rmax);
        }
        return sum;
    }
};