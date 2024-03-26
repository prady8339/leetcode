class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==1 ){
            if(nums[0]!=1)
 return 1;
            else return 2;
         
        }
      bool pass = 0;
        map<int,int> un;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]>0){
                pass = 1;
                 un[nums[i]]++;
            }
          
        } 
        if(pass==0) return 1;
        int i = un.begin()->first,j=0;
        if(i>1) return 1;
        for(auto it = un.begin() ; it!=un.end() ;it++){
           if(it->first!=i+j) return i+j;
            j++;
            
        }
        return i+j;
    }
};