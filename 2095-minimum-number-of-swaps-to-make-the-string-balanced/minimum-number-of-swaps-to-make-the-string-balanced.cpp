class Solution {
public:
    int minSwaps(string s) {
      int stx = 0;
      for(auto &x : s)  {
        if(x == '[') stx++;
        else{
            if(stx > 0) stx--;
        }
      }
      return ( stx + 1 ) / 2;
    }
};