class Solution {
public:
    int minOperations(string s) {
        int a = 0, b = 0, n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(i & 1)
                s[i] == '1' ? a++ : b++;  
            else
                s[i] == '0' ? a++ : b++;
        }
        return min(a, b);
    }
};