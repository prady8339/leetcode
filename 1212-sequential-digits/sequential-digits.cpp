class Solution {
private:
    void solve(vector<int> &ans, int low , int high, int tp){
        int dig = log10(tp) + 1;
        string d;
        for(int i = 0; i < dig ; i++){
            d += '1';
        }
        int mask = stoi(d);
        while(tp <= high ){
            if(tp >= low && tp<= high){
                ans.push_back(tp);
            }
            if(tp % 10 == 9) break;
            tp += mask;
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        int num = 123456789;
        stack<int> st;
        while(num){
            if(num >= low && num <= high){
                st.push(num);
            }
            num/=10;
        }
        string s = to_string(low);
        bool f = 1;
        for(int i = 1; i < s.size() ; i++){
            if(s[i -1] == 9){ f= 0; break;}
            s[i] = char (s[i-1] + 1);
        }
        int x = stoi(s);
        if(!st.empty()){
            // cout<<low<<" "<<x;
            if(f && st.top() != x){
                st.push(x);
            }
        }else{
            if(f)
            st.push(x);
        }
        vector<int> ans;
        while(!st.empty()){
            solve(ans, low , high, st.top());
            st.pop();
        }
        return ans;
    }
};