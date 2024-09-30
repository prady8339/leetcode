class CustomStack {
public:
    int mxSize;          
    vector<int> st;       

    CustomStack(int maxSize) {
        mxSize = maxSize;
    }

    void push(int x) {
        if (st.size() < mxSize) {
            st.push_back(x);
        }
    }

    int pop() {
        if (!st.empty()) {
            int lastElement = st.back();  
            st.pop_back();
            return lastElement;          
        }
        return -1;                        
    }

    void increment(int k, int val) {
        for (int i = 0; i < k && i < st.size(); i++) {
            st[i] += val; 
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
