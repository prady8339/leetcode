/**
 * @param {number[]} score
 * @return {string[]}
 */
var findRelativeRanks = function(score) {
    let ans = score;
    let clone = [];
    for(let i = 0 ; i < score.length ; i++){
        clone.push(
            {  score: score[i],idx: i}
        );
    }
    clone.sort((a,b) => b.score - a.score);
    for(let i = clone.length-1 ; i >= 0; i--){
        let idx = clone[i].idx;
        if(i == 0) ans[idx] = "Gold Medal";
        if(i == 1) ans[idx] = "Silver Medal";
        if(i == 2) ans[idx] = "Bronze Medal";
        if(i > 2)
        ans[idx] = (i + 1).toString();
        
    }
    return ans;
};