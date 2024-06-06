class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       sort(hand.begin(),hand.end());
       unordered_map<int,int> mp;
       for(auto &x : hand) mp[x]++;
       for(int i = 0; i < hand.size() ; i++){
        int currVal = hand[i];
        if(mp[currVal] == 0) continue;
        for(int j = 0 ; j < groupSize ; j++){
            if(mp[currVal + j] <= 0) return false;
            mp[currVal + j]--;
        }
       }
       return true;
    }
};

// 1 2 2 3 3 4 6 7 8

// 1 2 2 1 1 1 1 