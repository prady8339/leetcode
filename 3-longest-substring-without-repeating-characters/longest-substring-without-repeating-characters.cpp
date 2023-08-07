class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0 , j = 0;
        unordered_map<char,int> un;
        int count=0;
        int maxi = 0 ;
        while(j<s.size()){
            if(count==0){
                maxi = max(maxi,j-i);
                un[s[j]]++;
                if(un[s[j]]>1) count++;
                
            }
                while(count>0){
                    un[s[i]]--;
                    if(un[s[i]]==1){
                        count--;
                    }
                    i++;
                }
                j++;
            
        }
        if(count==0) maxi = max(maxi,j-i);
        return maxi;
    }
};