class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> ans;
            priority_queue<pair<int,int>> pq;
            int i = 0 , j  = 0 ;
            while(j < nums.size()){
                if(j<k){
                    pq.push({nums[j],j});
                    j++;
                }else{
                    ans.push_back(pq.top().first);
                    pq.push({nums[j],j});
                    j++;
                    i++;
                    while(pq.top().second<i) pq.pop();
                }

            }
            if(!pq.empty()) ans.push_back(pq.top().first);
            return ans;
    }
};