class Solution {
public:
    int buyChoco(vector<int>& p, int money) {
        int m1 = INT_MAX, m2 = INT_MAX;
        int n = p.size();
        for(int i = 0 ; i < n ; i++){
            if(p[i] < m1){
                m2 = m1;
                m1 = p[i];
            }else if(p[i] < m2){
                m2 = p[i];
            }
        }
        if(m1 + m2 <= money)
            return money - m1 - m2;

        return money;
    }
};