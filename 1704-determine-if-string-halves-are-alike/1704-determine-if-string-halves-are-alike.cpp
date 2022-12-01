class Solution {
public:
    bool halvesAreAlike(string s) {
        int x=0,y=0;
        int i = 0;
        for(; i<s.length()/2 ; i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                x++;
            }
        }
        for( ; i<s.length() ; i++){
           if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                y++;
            } 
        }
        return x==y;
    }
};