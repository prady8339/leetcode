class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& san) {
        int n = stu.size();
        // t1 is 1 and t2 is 0
        int t1  = 0 , t2 = 0;
        for(auto &s : stu) t1+=s;
        t2 = n - t1;
       for(auto &s : san){
            if(s == 1 && t1 == 0) return t2;
            if(s == 0 && t2 == 0) return t1;
            s == 1 ? t1-- : t2--;
       } 
       return 0;
    }
};