class Solution {
public:
    double average(vector<int>& salary) {
        int mini = INT_MAX,maxi = INT_MIN;
        unsigned int sum = 0;
        for(int i = 0 ;i < salary.size() ; i++){
            mini = min(salary[i],mini);
            maxi = max(salary[i],maxi);
            sum+=salary[i];
        }
        return (double) (sum-mini-maxi) / (salary.size()-2);
     }
};