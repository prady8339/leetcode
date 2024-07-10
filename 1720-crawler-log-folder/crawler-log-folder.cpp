class Solution {
public:
    int minOperations(vector<string>& logs) {
        int num = 0;
       for(auto &l : logs){
        if(l == "../"){
            if(num > 0)
            num--;
        }else if(l != "./"){
            num++;
        }
       } 
       return num;
    }
};