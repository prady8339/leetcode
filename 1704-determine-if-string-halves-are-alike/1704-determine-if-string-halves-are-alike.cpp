class Solution 
{
public:
    bool halvesAreAlike(string s) {
        set<char> st = {'a','e','i','o','u','A','E','I','O','U',};
        int x=0,y=0;
        int i = 0;
        for(; i<s.length()/2 ; i++){
            auto fd = st.find(s[i]);
            if(fd!=st.end()) x++;
        }
        for( ; i<s.length() ; i++){
           auto fd = st.find(s[i]);
            if(fd!=st.end()) y++;
        }
        return x==y;
    }
};