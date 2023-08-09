class Solution {
private: 
bool check(int th,vector<int> &nums,int p){
    int ct = 0;
    //if(nums.size()<2) return 0;
    for(int i=0;i< nums.size()-1 ; i++){
        if(nums[i+1]-nums[i]<=th){ ct++; i++; }
    }
    return ct>=p;
}
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int start = 0,end=nums[n-1]-nums[0];
        int th = end;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(check(mid,nums,p)){
                th = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return th;
    }
};


