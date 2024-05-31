/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function(nums) {
   const mp = {};
   for(let i = 0 ; i < nums.length ; i++){
    if(mp.hasOwnProperty(nums[i])){
        mp[nums[i]] = mp[nums[i]] + 1;
    }else{
       mp[nums[i]] = 1;
    }
   } 
    let ans = [];
   for(const [key,value] of Object.entries(mp)){
    if(value == 1){
        ans.push(key);
    }
    console.log(key,value);
   }
   return ans;
};