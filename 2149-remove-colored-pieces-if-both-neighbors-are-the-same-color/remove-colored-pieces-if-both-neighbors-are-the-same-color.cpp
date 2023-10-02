class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int aMoves = 0, bMoves = 0;
        int countA = 0, countB = 0;
        for(int i = 0 ; i < n ; i++){
          if(colors[i]=='B'){
            countB++;
            if(countA>=3){
              aMoves += countA - 2;
            }
            countA = 0;
          }else{
            countA++;
            if(countB>=3){
              bMoves += countB - 2;
            }
            countB = 0;
          }
        }
        if(countB>=3){
              bMoves += countB - 2;
        }
        //countB = 0;
        if(countA>=3){
              aMoves += countA - 2;
        }
        //countA = 0;

      return aMoves > bMoves;
    }
};