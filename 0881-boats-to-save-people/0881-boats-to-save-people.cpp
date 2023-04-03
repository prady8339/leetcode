class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int r=people.size()-1,l=0,ct=0;
        while(l<=r){
            if(people[l]+people[r]<=limit){ l++; r--;}
            else r--;
            ct++;
        }
        return ct;
    }
};