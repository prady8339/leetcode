class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto &d: details){
            string age = d.substr(11,2);
            if(stoi(age) > 60) ans++;
        }
        return ans;
    }
};