class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ct = 0;
        int presum = 0;
        unordered_map<int,int> un;
        un[0]=1;
        for(int i = 0 ; i < n ;i++){
            presum+=nums[i];
            if(un.count(presum-k)){
                ct+=un[presum-k];
            }
            un[presum]++;
        }
        return ct;
    }
};


//   unordered_map<int,int>m;
//         int s=0;
//         int c=0;
//         m[0]=1;
//         for(int i=0;i<nums.size();i++){
//             s+=nums[i];  // calculating prefix sum [sum from 0 to i]
//             if(m.find(s-k)!=m.end()){
//                 c+=m[s-k];  // adding no of prefix sums encountered till now with sum s-k.
//             }
//             m[s]++; // adding prefix sum to the map
//         }
//         return c;