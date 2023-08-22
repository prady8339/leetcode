class Solution {
public:
    string convertToTitle(int colNumber) {
        string colTitle;
        
        while(colNumber){
            colNumber--;
            char c = colNumber % 26 + 'A';
            colTitle.push_back(c);
            colNumber/=26;
        }
        
        reverse(colTitle.begin(),colTitle.end());
        return colTitle;
    }
};