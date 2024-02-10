/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
    var res = 0;
    const n = s.length
    for(var i = 0 ; i < n ; i++){
        var l = i, r = i;
        while(l >= 0 && r <= n && s[l] == s[r]){
            l--; r++;
            res++;
        }

        l = i, r = i + 1;
        while(l >= 0 && r <= n && s[l] == s[r]){
            l--; r++;
            res++;
        }
    } 
    return res;
};