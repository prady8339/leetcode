class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
         fb.insert(fb.begin(),0);
        fb.push_back(0);
        for(int i = 1; i < fb.size()-1; ++i)
        {
            if(fb[i-1] + fb[i] + fb[i+1] == 0)
            {
                --n;
                ++i;
            }
                
        }
        return n <=0;
    }
};