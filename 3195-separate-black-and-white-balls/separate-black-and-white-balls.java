class Solution {
    public long minimumSteps(String s) {
       long count = 0;
       long oneCount = 0;
       for(int i = 0 ; i < s.length() ; i++){
        char ch = s.charAt(i);
        if(ch == '0'){
            count += oneCount;
        }else{
            oneCount++;
        }
       }
       return count;
    }
}