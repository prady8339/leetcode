class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<pair<int,int>> ds; 
    bool book(int start, int end) {
        for(auto &d : ds){
            int s = d.first;
            int e = d.second;
               if (start < e && end > s) {
                return false; 
            }
        }
        ds.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */