/**
 * @param {string[]} words
 * @return {string}
 */

var firstPalindrome = function(words) {
    const isPal = (word) =>{
    var l = 0, r = word.length-1;
        while(l <= r ){
            if(word[l] != word[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    for(const word of words){
        if(isPal(word)){
            return word;
        }
    }
    return "";
};