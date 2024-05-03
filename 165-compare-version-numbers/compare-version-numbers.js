/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    const v1arr = version1.split(".");
    const v2arr  = version2.split(".");

    let i = 0, j = 0 , n = Math.min(v1arr.length, v2arr.length);

    while(i < n && j < n){
        let num1 = parseInt(v1arr[i]);
        let num2 = parseInt(v2arr[j]);
        if(num1 < num2) return -1;
        if(num1 > num2) return 1;
        i++;
        j++;
    }
    if(v1arr.length == v2arr.length) return 0;

    let m = -1;
    if (v1arr.length < v2arr.length){
        m = v2arr.length;
        while(n < m) {
            let num1 = parseInt(v2arr[n]);
            if(num1 != 0) return -1;
            n++;
        }
    }else{
        m = v1arr.length;
        while(n < m) {
            let num1 = parseInt(v1arr[n]);
            if(num1 != 0) return 1;
            n++;
        }
    }
    return 0;
};