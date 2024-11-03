class Solution {
public:
    bool rotateString(string goal, string s) {
       if(s.size() != goal.size()) return false;
       int j = 0; 
       s += s;
       int prev = 0;
       for(int i = 0 ; i < s.size() ; i++){
        if(j < goal.size() && s[i] == goal[j]){
            j++;
        }else{
            if(j == goal.size()) return true;
            i -= j;
            j = 0;
        }
       }
       return j == goal.size(); 
    }
};


// "ceeb bbbacddceeb bbbacdd"
// "bbbacddceeb"
// abcdeabcde
// cdeab

